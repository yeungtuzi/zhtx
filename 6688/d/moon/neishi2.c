/* 再生草庐 内室1
   neishi.c */
   
inherit ROOM;
  
void create()
{
        set("short","客房");
        set("long", @LONG
这是一个比较宽敞的房间，阳光洒在铺着锦绣的床上，一名穿着大红袍的中年人正喜滋滋的坐在椅子上，不时地看看窗外，似乎在等什么
LONG
        );
        set("exits", ([ 
          "west" : __DIR__"zscl",
]));
        set("objects", ([
        __DIR__"npc/zhuzao" : 1,
                        ]) ); 
   setup();      
   replace_program(ROOM);
}
