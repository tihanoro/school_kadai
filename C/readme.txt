(C)の課題のファイル
figure.c・・・改良前ソースコード
figure_file.c・・・ソースコード
figure_file.log・・・実行結果
figure_file_flowchart.pdf,figure_file_flowchart.xlsx・・・フローチャート

考察
・stderrが必要な理由
リダイレクション対策に必要
パイプで渡したとき、エラー表示を標準出力に出力するとユーザー側に見せることができないが、標準エラー出力に出力するとパイプに渡されずディスプレイに表示される。

・scanfの危険性と回避策
バッファオーバーフローを考慮しない事。
バッファの終端を超えてデータを書き込まれて、予期せぬ不具合が生じることがある。
回避策は、fgetsを使って1行入力を行い、sscanfで文字列からデータを読み取る。
参考文献：https://ylb.jp/2006b/proc/fileio/stdin-out.html