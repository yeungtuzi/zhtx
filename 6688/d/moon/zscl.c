/* 再生草庐 堂屋
   zscl.c */
   
inherit ROOM;
  
void create()
{
        set("short", "再生草庐");
        set("long", @LONG
这是一间布置简单但很考究的屋子，庐中无论一杯一盏，一条一幅，俱是万金难求之珍物。
东面和西面的门上居然都各贴着一个喜字，难道有人要结婚了?窗户也是半掩着.
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"neishi1",
  "east" : __DIR__"neishi2",
  "south" : __DIR__"zscl5",
]));
        set("objects", ([
        __DIR__"npc/yunkeng" : 1,
                        ]) ); 
   setup();      
   replace_program(ROOM);
}
