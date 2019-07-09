このレポジトリーには小さなROSに関するC++のサンプルコードを
勉強用に上げていく予定です．

1.できるだけコードは短く,わかりやすく書くこと

2.C++11を使用して，最新のコードになるよう気をつけること

3.ラーメンは飲み物ということに気をつけること


*Usage
        $ cd ~/catkin_ws/
        $ catkina_make
        

*Description

        1.２つのプログラムを起動し，データをやりとりする．

        2.同じプログラムを複数の名前をつけて起動する
        $ roslauch simple_groupchat.launch

        3.同じプログラムを複数起動する．名前の衝突を避けるために名前空間を使用
        $ roslaunch simple_multi_groupchat.launch





