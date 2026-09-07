;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  XEmacs 用 ユーザ設定ファイルのサンプル
;;            MATSUBAYASHI 'Shaolin' Kohji (shaolin@vinelinux.org)
;;                modified by Jun Nishii (jun@vinelinux.org)
;;                modified by Hiroaki Irokawa (irorin@terra.dti.ne.jp)
;;                       Time-stamp: <2007/10/11 10:58:50 u000435g>


;;; 初期設定ファイルの指定
;;; ここで指定したファイルにオプション設定等が書き込まれます

(setq user-init-file "~/.xemacs/init.el")
(setq custom-file "~/.xemacs/custom.el")


;;; 漢字コードの指定

(set-default-coding-systems 'euc-jp)
(set-buffer-file-coding-system 'euc-jp-unix)

(if (eq (console-type) 'tty)
      (set-terminal-coding-system 'euc-jp))

;;;画面の色(カーソル：暗い赤色)、サイズ(横：80桁、縦：40行)

(setq default-frame-alist (append (list '(cursor-color . "purple")
                                        '(width .  80)
                                        '(height . 40))
                                  default-frame-alist))

;;; 一行が 80 字以上になった時には自動改行する
(setq fill-column 80)
(setq text-mode-hook 'turn-on-auto-fill)
(setq default-major-mode 'text-mode)

;;; 行数表示

(custom-set-variables '(line-number-mode t))

;;; gnuclient サーバを起動
(load "gnuserv")
(gnuserv-start)

;;; gzファイルも編集できるように
(auto-compression-mode t)

;; 環境変数 EMACS_IME を調べる。- 現在のところ、canna または Canna なら、
;; 「かんな」を使用する。それ以外の場合は Wnn を使用する。

(setq emacs-ime (getenv "EMACS_IME"))
(if (null emacs-ime)
    (setq emacs-ime "wnn7"))
;     (setq emacs-ime "anthy"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Egg (Wnn フロントエンド) の設定
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Wnn6/FreeWnn
(if (or (equal emacs-ime "wnn")
        (equal emacs-ime "Wnn")
        (equal emacs-ime "wnn6")
        (equal emacs-ime "Wnn6"))
  (progn
    (load "egg")
    (global-set-key "\C-\\" 'toggle-input-method)

    (set-input-method "japanese-egg-wnn")
    (set-language-info "Japanese" 'input-method "japanese-egg-wnn")

    (setq egg-default-startup-file "eggrc-wnn") ; 95.6.1 by S.Tomura
    (garbage-collect)

    ;; jserver のリストを次の様にして指定できます
    ;;(setq jserver-list '("vanilla" "espresso"))
    (setq jserver-list (list (getenv "JSERVER") "localhost"))

    ;; "nn" で「ん」を入力
    (setq enable-double-n-syntax t)

    ;; "." で「．」、"," で「，」を入力。 
    (setq use-kuten-for-period nil)
    (setq use-touten-for-comma nil)

    ;; 1234567890%#%"' を「半角」で入力"
    (let ((its:*defrule-verbose* nil))
    (its-define-mode "roma-kana")
    (dolist (symbol '("1" "2" "3" "4" "5" 
    		  "6" "7" "8" "9" "0"
    		  "#" "%" "\"" "'" ))
    	(its-defrule symbol symbol)))

    ;; おまけ :-)
    ;;(set-egg-fence-mode-format "♪" "♪" 'highlight)
    )
)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Wnn7Egg (Wnn7 フロントエンド) の設定
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(if (or (equal emacs-ime "wnn7")
        (equal emacs-ime "Wnn7"))
    (progn
      (setq load-path (append '("/usr/share/wnn7/elisp/xemacs21") load-path))
      (global-set-key "\C-\\" 'toggle-input-method)
      ;; (global-set-key "\C-o" 'toggle-input-method)
      (load "wnn7egg-leim")
      (set-input-method "japanese-egg-wnn7")
      (set-language-info "Japanese" 'input-method "japanese-egg-wnn7")

      ;; "nn" で「ん」を入力
      (setq enable-double-n-syntax t)
      ;; 候補選択モード
      (egg-use-input-predict)
      (setq egg-predict-realtime nil)
      ;; インライン候補選択モード
      (setq egg-predict-mode "inline")
      ;; ウインドウ候補選択モード
      ;(setq egg-predict-mode "window")

      ;; 候補リスト表示
      (define-key wnn7-henkan-mode-map " " 'wnn7-henkan-select-kouho-dai)

      ;; 1234567890%#%"'/\| を「半角」で入力
      (let ((its:*defrule-verbose* nil))
        (its-define-mode "roma-kana")
        (dolist (symbol '("1" "2" "3" "4" "5" 
                          "6" "7" "8" "9" "0"
                          "#" "%" "\"" "'" "/" "\\" "|"))
                (its-defrule symbol symbol)))
    )
)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; かんなの設定
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(if (or (equal emacs-ime "canna")
	(equal emacs-ime "Canna")
	)
   (progn
      (load-library "canna")

      ;; color-mate を使わないで、漢字変換に色を付けたい時に
      (setq canna-use-color t)

      ;; フェンスモードでなくアンダーラインを使う
      ;;(setq canna-with-fences nil)
      ;;(setq canna-underline t)

      ;; Canna サーバの指定
      (if (null (getenv "CANNA_SERVER"))
	  (setq canna-server "unix")
	(setq canna-server (getenv "CANNA_SERVER")))
      (canna)

      (global-set-key "\C-_" 'canna-undo)  ;アンドゥの設定。
      (setq canna-save-undo-text-predicate ;アンドゥバッファへ入れる条件
            '(lambda (s) (> (length (car s)) 2)) )
      (setq canna-undo-hook ;アンドゥ＋α。
            '(lambda () (message "再変換します....")                          
               (canna-do-function canna-func-henkan)) )

      ;;かんなの変換中に BS & DEL を使う
      ;;(define-key canna-mode-map [backspace] [?\C-h])
      ;;(define-key canna-mode-map [delete] [?\C-h])

      ;;かんなの変換中に C-h を使う (with term/keyswap)
      (define-key canna-mode-map [?\177] [?\C-h])

      (set-input-method 'japanese-canna)
   )
)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; XEmacs のフォント/カラー設定
;; (color-mate を使わない時に色をつける設定．)
;; XEmacs には hilit19 がないので，色はつきませんが，
;; 代りに font-lock を使って簡易ですが色をつけられます．
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(set-face-foreground 'default "black" nil '(x color))
(set-face-background 'default "#eeeeff" nil '(x color))

(require 'font-lock)
(setq font-lock-verbose nil)
(put 'yatex-mode 'font-lock-defaults 'tex-mode)
(put 'yahtml-mode 'font-lock-defaults 'html-mode)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; XEmacs で色を付ける (color-mate の設定読み込み)
;; Vine Linux 2.1 までの旧式の設定
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;(load "~/.emacs-color.el")


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Mule-UCS の設定
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(require 'un-define)
(set-coding-priority-list '(utf-8))
(set-coding-category-system 'utf-8 'utf-8)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; SEMI
;;   Vine 1.9 からは tm (Tiny Mime) の代わりに semi を使います
;;   (Mew は tm や semi なしでも MIME に対応しています)
;;
;; /etc/xemacs-??.?.??/site-start.d/51semi-init.el
;; を読み込みます
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;(require 'mime-setup)
;(load "path-util")
;(setq rmail-enable-mime t)

;; rail-1.0.2 を使って User-Agent: フィールドのコードネームを日本語化する
(setq rail-emulate-genjis t)
(if (module-installed-p 'rail) (load "rail"))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; T-Gnus 6.13.3 (参考)
;;   NetNews リーダー GNUS (SEMI 対応版)
;;   M-x gnus で起動します
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; News Server 名やドメイン名を適切に指定してください
;(setq gnus-nntp-server "news.hoge.hoge.or.jp")
;(setq gnus-local-domain "hoge.hoge.or.jp")
;(setq gnus-local-organization "HogeHoGe Org.")
;(setq gnus-use-generic-from t)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; w3
;;   XEmacs 上で動くブラウザです
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;   

;; w3 でプロキシの設定が必要な場合、
;; ~/.w3/profile 内の設定を編集して下さい.
;; 書式は以下の通りです.
;(setq url-proxy-services '(
;      ("http" . "http://proxy.nowhere.ne.jp:8080/")
;      ("ftp" . "http://proxy.nowhere.ne.jp:8080/")
;      ("gopher" . "http://proxy.nowhere.ne.jp:8080/")
;      ("no_proxy" . "://[^/]*nowhere.ne.jp/\\|://192.168"))
;    url-using-proxy t)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Mew -  Messaging in the Emacs World
;;   メールリーダー Mew
;;   M-x mew で起動します
;;   これ以外の設定は ~/.mew.el で行います
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(autoload 'mew "mew" nil t)
(autoload 'mew-send "mew" nil t)

;; Toolbarに追加
;(setq toolbar-mail-commands-alist (quote ((mew . mew) )))
;(setq toolbar-mail-reader (quote mew))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Wanderlust
;;   IMAP にも対応したメール/ニュースリーダ
;;   これ以外の設定は ~/.wl で行います
;;   ~/.wl のサンプルは /usr/share/doc/Wanderlust-?.??.? 以下にあります
;;
;; /etc/xemacs-??.?.??/site-start.d/55wl-init.el
;; を読み込みます
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;(autoload 'wl "wl" "Wanderlust" t)
;(autoload 'wl-draft "wl" "Write draft with Wanderlust." t)

;; Toolbarに追加
;(setq toolbar-mail-commands-alist (quote ((wl . wl) )))
;(setq toolbar-mail-reader (quote wl))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; X-Face
;;   Mew や Wanderlust などで、X-Face 画像つきのメッセージを表示します
;;;  /usr/share/doc/x-face-xemacs-1.3.6.23/README.ja
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(when (and window-system (module-installed-p 'x-face))
   (autoload 'x-face-xmas-mew-display-x-face "x-face" nil t)
   (setq wl-highlight-x-face-function
      'x-face-xmas-mew-display-x-face)
   (setq x-face-add-x-face-version-header t))

;; 起動画面を表示しない
;(setq x-face-inhibit-loadup-splash t)

;;; 多階調 X-Face 作成
;;; M-x convert-image-to-gray-x-face で起動します
;(autoload 'convert-image-to-gray-x-face "make-gray-x-face" nil t)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; irchat-pj-2.4.24.07
;;   IRC (チャット) クライアントの設定
;;   M-x irchat で起動します
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(autoload 'irchat "irchat" nil t)

;;; IRC server の指定
;;; (いずれか一つをコメントアウトします)
;;(setq irchat-server "irc.tohoku.ac.jp")
;;(setq irchat-server "irc.kyutech.ac.jp")
;;(setq irchat-server "irc.tokyo.wide.ad.jp")
;;(setq irchat-server "irc.kyoto.wide.ad.jp")
;;(setq irchat-server "irc.huie.hokudai.ac.jp")
;;(setq irchat-server "irc.cc.yamaguchi-u.ac.jp")
;;(setq irchat-server "irc.karrn.ad.jp")
;;(setq irchat-server "irc.kyoto.wide.ad.jp")

;;; ユーザー名とニックネーム
;;; (nick は半角英数および []{}_\^ からなる最大 9 文字の文字列です)
(setq irchat-name "IRC sample user")
(setq irchat-nickname "PJEtest")

;;; デフォルトで参加するチャンネルのリスト
;;;  （ここに書いたチャンネルには irchat の起動と同時に参加できます）
;;(setq irchat-startup-channel-list '("#linuxjp,#pjetest"))
(setq irchat-startup-channel-list '("#VineUsers"))

;;; オプション
;;;   詳細は /usr/doc/irchat-pj-xemacs-2.4.24.07/doc 以下のファイルを参照
(setq irchat-reconnect-automagic t)      ; 切れた場合に再接続を試みる
;;(setq irchat-channel-buffer-mode t)    ; チャネル分割表示モード
;;(setq irchat-display-channel-always t)
;;(setq irchat-default-freeze-local nil)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; YaTeX 1.67
;;   [La]TeX 入力モード
;;   M-x yatex とするか、.tex で終わるファイルを読み込むと起動します
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(autoload 'yatex-mode "yatex" "Yet Another LaTeX mode" t)

;; YaTeX-mode
(setq auto-mode-alist
      (cons (cons "\\.tex$" 'yatex-mode) auto-mode-alist))
(setq dvi2-command "xdvi"
      tex-command "platex"
      dviprint-command-format "dvips %s | lpr"
      YaTeX-kanji-code 3)

;; YaHtml-mode
(setq auto-mode-alist
      (cons (cons "\\.html$" 'yahtml-mode) auto-mode-alist))
(autoload 'yahtml-mode "yahtml" "Yet Another HTML mode" t)
(setq yahtml-www-browser "mozilla")


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; ホイールマウス対応
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;=============================================================================
;;                    scroll on  mouse wheel
;;=============================================================================
;; scroll on wheel of mouses
(define-key global-map 'button4
  '(lambda (&rest args)
    (interactive)
    (let ((curwin (selected-window)))
      (select-window (car (mouse-pixel-position)))
      (scroll-down 5)
      (select-window curwin)
)))
(define-key global-map [(shift button4)]
  '(lambda (&rest args)
    (interactive)
    (let ((curwin (selected-window)))
      (select-window (car (mouse-pixel-position)))
      (scroll-down 1)
      (select-window curwin)
)))
(define-key global-map [(control button4)]
  '(lambda (&rest args)
    (interactive)
    (let ((curwin (selected-window)))
      (select-window (car (mouse-pixel-position)))
      (scroll-down)
      (select-window curwin)
)))
(define-key global-map 'button5
  '(lambda (&rest args)
    (interactive)
    (let ((curwin (selected-window)))
      (select-window (car (mouse-pixel-position)))
      (scroll-up 5)
      (select-window curwin)
)))
(define-key global-map [(shift button5)]
  '(lambda (&rest args)
    (interactive)
    (let ((curwin (selected-window)))
      (select-window (car (mouse-pixel-position)))
      (scroll-up 1)
      (select-window curwin)
)))
(define-key global-map [(control button5)]
  '(lambda (&rest args)
    (interactive)
    (let ((curwin (selected-window)))
      (select-window (car (mouse-pixel-position)))
      (scroll-up)
      (select-window curwin)
)))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; その他の設定
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; マクロサーチパスの追加
;;; ~/lib/emacs 以下にユーザ用の *.el, *.elc を置くことができます
;;(setq load-path (append '("~/lib/emacs") load-path))


;;; ステータスラインに時間を表示する
(display-time)


;;; rpm-mode の読み込み
;;; rpm-mode.el は spec ファイルの作成に便利です。
;;;   ~/lib/emacs に /usr/doc/rpm/rpm-mode.el をコピーして以下の設定を
;;; 行ってください。

;(setq auto-mode-alist (nconc '(("\\.spec" . rpm-mode)) auto-mode-alist))
;(autoload 'rpm-mode "rpm-mode" "Major mode for editing SPEC file of RPM." t) 
;(setq packager "Vine User <vine@hoge.fuga>");自分の名前
;      (setq buildrootroot "/tmp");BuildRootの場所
;      (setq projectoname "Project Vine");プロジェクト名 


;;; 最終更新日の自動挿入
;;;   ファイルの先頭から 8 行以内に Time-stamp: <> または
;;;   Time-stamp: " " と書いてあれば、セーブ時に自動的に日付が挿入されます
(if (not (memq 'time-stamp write-file-hooks))
    (setq write-file-hooks
          (cons 'time-stamp write-file-hooks)))


;;;バッファの最後でnewlineで新規行を追加するのを禁止する
(setq next-line-add-newlines nil)

;;;印刷設定
(setq-default lpr-switches '("-1P"))
(setq-default lpr-command "mpage")

;;; キーバインド定義
(global-set-key [backspace] 'delete-backward-char) ; BS
(global-set-key [delete] 'delete-char)             ; DEL
(global-set-key "\C-h" 'delete-backward-char)      ; C-h(=DEL)
(global-set-key "\M-?" 'help-for-help)             ; M-?(=help)
(global-set-key [home] 'beginning-of-buffer)       ; HOME(バッファの先頭に飛ぶ)
(global-set-key [end] 'end-of-buffer)              ; END(バッファの最後に飛ぶ)

;;; アプリメニューにいろいろ追加する設定
;;; http://www.jmos.net/xemacs/#menu
;(add-menu-button '("Apps")          ["navi2ch"  navi2ch  t])
;(add-menu-button '("Apps")          ["Liece" liece t])
;(add-menu-button '("Apps")          ["w3m" w3m t])
;(add-menu-button '("Apps")          ["speedbar" speedbar t])
;(add-menu-button '("Apps")          ["TiMidity++" timidity t])


;;; スクロールを1行単位にする
(setq scroll-step 1)

;;; *.~ とかのバックアップファイルを作らない
;(setq make-backup-files nil)

;;; .#* とかのバックアップファイルを作らない
;(setq auto-save-default nil)

;;; 以前編集したファイルのカーソル位置を覚える設定
(require 'saveplace)
(setq-default save-place t)

;; scratch モードの最初のメッセージは消す
(setq initial-scratch-message nil)

;;; C-t、M-C-tでバッファの高速切り替え
(defun previous-buffer ()
  "Select previous window."
  (interactive)
  (bury-buffer))
(defun backward-buffer ()
  "Select backward window."
  (interactive)
  (switch-to-buffer
   (car (reverse (buffer-list)))))
(global-set-key "\C-t"    'previous-buffer)
(global-set-key "\M-\C-t" 'backward-buffer)


;; Info では frame-title に詳しい情報を
(add-hook 'Info-startup-hook
          #'(lambda ()
              (make-local-variable 'frame-title-format)
              (setq frame-title-format
                    (concat "*info*  ("
                            (file-name-nondirectory
                             (if (stringp Info-current-file)
                                 Info-current-file
                               (or buffer-file-name "")))
                            ")  "
                            Info-current-node))))
(add-hook 'Info-select-hook
          #'(lambda ()
              (setq frame-title-format
                    (concat "*info*  ("
                            (file-name-nondirectory
                             (if (stringp Info-current-file)
                                 Info-current-file
                               (or buffer-file-name "")))
                            ")  "
                            Info-current-node))))

;;; gutter を表示しない
;(setq gutter-buffers-tab-enabled nil)







;;; -*- Emacs-Lisp -*-

;;; 英和辞書閲覧 sdic-mode の設定


;; Debian 用パッケージを使ってインストールした場合、(autoload 〜) は 
;; /etc/emacs/site-start.d/50sdic で行っていますので、キーバインドの設
;; 定 (global-set-key 〜) のみで十分です。

(setq load-path (cons "/usr/share/emacs/site-lisp" load-path))
(autoload 'sdic-describe-word "sdic" "英単語の意味を調べる" t nil)
(global-set-key "\C-cw" 'sdic-describe-word)
(autoload 'sdic-describe-word-at-point "sdic" "カーソル位置の英単語の意味を調べる" t nil)
; (global-set-key "\C-cW" 'sdic-describe-word-at-point)



;; これは、動作と見掛けを調節するための設定です。
(setq sdic-window-height 10
      sdic-disable-select-window t)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Last Up date を挿入する  10/6/02 by hashimoto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
  (defun save-buffer-wrapper ()
    (interactive)
    (let ((tostr (concat "$Last Updated: " (current-time-string) " $")))
      (save-excursion
        (goto-char (point-min))
        (while (re-search-forward
                "\\$Last Updated\\([A-Za-z0-9: ]*\\)?\\$" nil t)
          (replace-match tostr nil t)))
      (save-buffer)))

  (global-set-key "\C-x\C-s" 'save-buffer-wrapper)
;;
(setq minibuffer-max-depth nil)




;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; このファイルに間違いがあった場合に全てを無効にします
(put 'eval-expression 'disabled nil)
