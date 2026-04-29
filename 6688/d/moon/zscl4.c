/* 通往再生草庐的小路 紫心剑客盛存笑

盛存笑的秘密:

   0: 向铁中堂打听云铿的事情
   1: talk shen cunxiao.帮助他把解药送给柳荷衣(铁匠村东口的树下面的冷面少女）
   2: 把柳交给你的掌伤解药送给盛大娘。
   3: 盛存孝感激你，告诉你大家准备拜见再生草庐主人，你告知朱藻和水的婚事
   4: 盛存孝大惊，告诉你一段往事，原来朱和水是兄妹
   5: 你去阻拦该婚事，不得已和交战，战胜对方后（不得有任何人帮助,armor,avf都
清零),告诉他们真相.
   6: 回到盛那里,领赏(可以学习断绝神功 duanjue-shengong)
   7: 去夜帝那里领赏(可以学习制造术making)

   zscl4.c */
   
inherit ROOM;
  
void create()
{
       set("short", "王屋山小路");
        set("long", @LONG
此处王屋山中，耳畔但闻得山林松涛,一个中年剑客站在那里，也许可以上去问问
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"zscl5",
  "southdown" : __DIR__"zscl3",
]));
        set("objects", ([
        __DIR__"npc/shencunxiao" : 1,
                        ]) ); 
   setup();      
   replace_program(ROOM);
}
