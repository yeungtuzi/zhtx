/* 通往再生草庐的小路 黄冠剑客与碧月剑客 钱大河、孙小娇

   zscl3.c */
   
inherit ROOM;
  
void create()
{
        set("short", "王屋山小路");
        set("long", @LONG
此处王屋山中，耳畔但闻得山林松涛,一对男女走在前面
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"zscl4",
  "northdown" : __DIR__"zscl2",
]));
        set("objects", ([
        __DIR__"npc/qiandahe" : 1,
        __DIR__"npc/sunxiaojiao" : 1, 
                        ]) ); 
   setup();      
   replace_program(ROOM);
}
