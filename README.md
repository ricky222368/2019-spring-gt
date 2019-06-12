1.解題邏輯

a.  用於有向圖的。

b.  由於必須先找出out-degree, in-degree的部分，圖論中的一個定理表明，且圖的所有頂點的in-degree and out-degree相同時，圖形才具有Euler Tour，因此如果向圖加入其他路徑，能去達到in-degree and out-degree都足以做匹配。

c.  通過加入其他路徑，我們的目標是平衡圖形的所有頂點的in-degree和out-degree，因為只有這樣才能存在Euler Tour。

d.  需要找的是最小的路徑，因此這匹配的過程中，必須要選擇最短的路徑去做match。

e.  我們依然要找出Euler Tour，因此使用了Hierholzer方法，那麼最佳的路徑的cost就會是Euler Tour的所有路徑的weight。

---------------------------------------------------------------------------------------------------------------------------------------
2.程式碼實作

a.  創立一個topo.txt，也就是graph的點跟邊以及weight的關係的文件檔，利用interpret這個function去建立。

b.  head_tail_value這個class，主要是方便後面去做存取的動作。

c.  做一個Degree的function，用來找每一個vertex的degree數，利用out_degree - in_degree。

d.  find_path這個function來找兩點之間的最短路徑值

e.  用一個W的vector來存放flowval的值，接著用到vector iterator中的min_element(begin, end) 來判斷第幾個值是最小的。

f.  一開始先print出所有的edge, vertex來判斷是否與原圖相符。

g.  接著宣告2個vector<string>是用來放pos_degree,neg_degree的vector，利用get_all_node來做find degree的部分，接著val是用來存find_min_path出來的值的部分，二維的head_tail_value的vector min是用來存放我在比較pos_degree以及neg_degree需要如何配對的。
  
h.  利用do while來做判斷，while內的判斷主要是由next_permutation和prev_permutation去做判斷是否每一種組合都有配對到，我是利用neg這個vector去做排列組合，交換進而達到所有組合都有去配對到，然後再將所有組合存放到剛剛有提到的min的二維vector，count主要是用來記，我這個配對組合是第幾個放入min二維vector的，然後再去算min二維vector裡面的組合，哪一條是最小的值。

i.  接著find_min_path又用到一次，不過因為是要找到path，所以沒有去改上面的find_min_path，而直接在使用一次並且加入其他的作用，size主要是判斷，那個iter指向最小值的位置，是和第一個位置差距多遠，找到後就去做connect的部分，之後再把P_ vector做初始化，重複做，看min有幾列(count_i)就做幾次。

j.  利用Hierholzer’s Algorithm來做存取以及print出整個路徑，因為有一些int以及string的問題，所以我把它們做一些轉換(abc, 123的轉換)，以便處理。

k.創一個outfile去做吐檔的部分。

l.  利用elist去算出所有edge的flowval值，不過因為有做connect的幾條edge他的value會是0，無法set value，因此額外加的那幾條edge的value會是0，在這邊我是一樣算出所有edge的value後，在將所算出的min_path的值加上去，就會是所有路徑的weight也就是最後print出來的cost值。

---------------------------------------------------------------------------------------------------------------------------------------
3.執行

只需在此資料夾內使用 make 即可編譯，得出執行檔main.out， 使用./main.out 直接執行，以及會產生outfile.txt
輸出尤拉路徑的檔案。
make clean可清除main.out、outfile.txt
