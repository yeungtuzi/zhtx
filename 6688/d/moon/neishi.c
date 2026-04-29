/* 再生草庐 内室1
   neishi.c */
   
inherit ROOM;
  
void create()
{ 
        set("short","新房");
        set("long", @LONG
这里挂红堆绿，满室锦绣，果然是新房。锦绣堆中，端坐着凤冠霞
披的新人，只是不知为何，新人忽而顿足，忽而皱眉，忽而用手塞住耳朵——似乎笑声越是
欢乐，她心里便越是悲伤，桌上还摆着一面菱花铜镜。

LONG
        );
        set("exits", ([ 
         "east" : __DIR__"neishi1",
]));
        set("objects",([   
        __DIR__"npc/shuilingguang" : 1,
                        ]) ); 
   setup();      
   replace_program(ROOM);
}
