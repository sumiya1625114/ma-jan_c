# ma-jan

![png](https://github.com/sumiya1625114/ma-jan_c/blob/main/sample_c.png)

## Overview

個人的な勉強用のリポジトリです。  
麻雀ゲーム(東一局のみ/CPUツモ切りのみ)　※未完成　 

内部設計のみの開発のため、UIはプロンプト上に簡素的に表示するだけです。  
そのため想定外の操作ができてしまいますが、通常の操作のみ行った場合を想定して内部処理を作成しています。  
（2019年作成　業務が忙しくなり頓挫）  

## 環境

<!-- 言語、フレームワーク、ミドルウェア、インフラの一覧とバージョンを記載 -->

| 言語・フレームワーク  | バージョン |
| --------------------- | ---------- |
| C++                   | 14         |

## 現状の問題
・想定外の操作   
UIが実装されていないため仕方ないが、鳴き後に空いた牌を捨てる等の操作ができてしまう   

・リーチ後鳴ける  
リーチ後もポンチーできてしまう  

・鳴き牌の動作がおかしい  
鳴き牌の配列が正しく読み込まれない。鳴き後想定外の鳴き・和了ができてしまう。  
