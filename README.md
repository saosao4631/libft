*TThis project has been created as part of the 42 curriculum by ksaotome.*

# libft

## Description
- 42 curriculum

| 項目 | 内容 |
|------|------|
| **Program Name** | `libft.a` |
| **Files to Submit** | `Makefile`, `libft.h`, `ft_*.c` |
| **Makefile** | `NAME`, `all`, `clean`, `fclean`, `re` |
| **External Functions** | 各関数ごとに個別に許可 |
| **Libft authorized** | n/a（libft 自身の課題のため） |
| **Description** | 自分自身のライブラリを作成する：以降のカリキュラムで役立つ関数群のコレクション |

### 要件

- グローバル変数は禁止
- 補助関数は`static`で同一ファイル内に閉じる
- 全ファイルをリポジトリのルートに配置
- 未使用ファイルの提出は禁止
- 全`.c`ファイルが`-Wall -Wextra -Werror`で通る
- `ar`コマンドでアーカイブを作成
- `libft.a`はリポジトリのルートに生成

## Instructions

### 必要環境

- C コンパイラ（`cc` または `gcc`）
- GNU Make
- 動作確認環境: macOS / Linux

### コンパイル

リポジトリのルートで以下を実行すると、静的ライブラリ `libft.a` が生成される。

```bash
make
```

| `make` / `make all` | `libft.a` をビルド |
| `make clean` | オブジェクトファイル（`.out/`）を削除 |
| `make fclean` | `libft.a` とオブジェクトファイルを削除 |
| `make re` | `fclean` 後に再ビルド |

### Part 1

| 関数 | 機能 |
|------|------|
| `ft_isalpha` | 英字判定 |
| `ft_isdigit` | 数字判定 |
| `ft_isalnum` | 英数字判定 |
| `ft_isascii` | ASCII範囲判定 |
| `ft_isprint` | 印字可能文字判定 |
| `ft_toupper` | 小文字 → 大文字変換 |
| `ft_tolower` | 大文字 → 小文字変換 |
| `ft_strlen` | 文字列長を返す |
| `ft_memset` | メモリを指定値で埋める |
| `ft_bzero` | メモリをゼロクリア |
| `ft_memcpy` | メモリをコピー（領域の重複不可） |
| `ft_memmove` | メモリをコピー（領域の重複可） |
| `ft_memchr` | メモリ内から特定バイトを探索 |
| `ft_memcmp` | メモリを比較 |
| `ft_strlcpy` | 文字列をサイズ制限付きでコピー |
| `ft_strlcat` | 文字列をサイズ制限付きで連結 |
| `ft_strchr` | 文字列内から文字を前方探索 |
| `ft_strrchr` | 文字列内から文字を後方探索 |
| `ft_strncmp` | 文字列をサイズ制限付きで比較 |
| `ft_strnstr` | 文字列内から部分文字列を探索 |
| `ft_atoi` | 文字列を `int` に変換（標準 `atoi` 互換） |
| `ft_calloc` | ゼロクリアされた領域を動的確保 |
| `ft_strdup` | 文字列を複製（`malloc` で領域確保） |

### Part 2

| 関数 | 機能 |
|------|------|
| `ft_substr` | 部分文字列を切り出して新規確保 |
| `ft_strjoin` | 2つの文字列を連結した新文字列を確保 |
| `ft_strtrim` | 先頭・末尾から指定文字集合を除去 |
| `ft_split` | 区切り文字で文字列を分割し `char **` を返す |
| `ft_itoa` | `int` を文字列に変換（`INT_MIN` 対応） |
| `ft_strmapi` | 各文字に関数を適用して新文字列を生成（インデックス付き） |
| `ft_striteri` | 各文字に関数を適用してインプレース変更（インデックス付き） |
| `ft_putchar_fd` | 文字を指定 fd に出力 |
| `ft_putstr_fd` | 文字列を指定 fd に出力 |
| `ft_putendl_fd` | 文字列 + 改行を指定 fd に出力 |
| `ft_putnbr_fd` | 整数を指定 fd に出力 |

### Part 3

片方向連結リストのノード構造体 `t_list` と、それを操作する関数群。

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| 関数 | 機能 |
|------|------|
| `ft_lstnew` | 新規ノードを生成 |
| `ft_lstadd_front` | リスト先頭にノードを追加 |
| `ft_lstadd_back` | リスト末尾にノードを追加 |
| `ft_lstsize` | リストのノード数を返す |
| `ft_lstlast` | リストの末尾ノードを返す |
| `ft_lstdelone` | 単一ノードの content を解放して削除 |
| `ft_lstclear` | リスト全体を解放 |
| `ft_lstiter` | 各ノードの content に関数を適用 |
| `ft_lstmap` | 各ノードの content に関数を適用して新リストを生成 |

## Resources

### 公式ドキュメント・リファレンス

- [usatile/libft-tester-tokyo](https://github.com/usatie/libft-tester-tokyo) — テストツール
- [だえうホームページ](https://daeudaeu.com/list-structure/) — リスト構造説明サイト
- [Qiita](https://qiita.com/lightfel/items/04d293ccf2b2184ddc26) — 関数ポインタ説明ブログ


### AI の活用について

本プロジェクトでは Claude を以下の用途で活用した：

| 用途 | 対象部分 |
|------|---------|
| 要件の日本語訳 | 課題要件の正確な把握のため、翻訳に利用 |
| READMEの作成補助 | マークダウン形式への変換・整形 |
| テスト（main部分）の作成補助 | 実装範囲外での可読性、テスト結果をわかりやすくする目的で整形 |