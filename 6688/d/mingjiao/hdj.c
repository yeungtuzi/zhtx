
inherit ROOM;

void create()
{
        set("short", "蝴蝶居");
        set("long", @LONG
	青青的软竹搭成小小的竹屋。屋中几乎所有的家具都是用青
竹编成的。主人胡青牛夫妇面有忧色，正在商量着什么。西边是一个
小小的药房。
LONG
        );
        set("exits", ([ 
  "out" : __DIR__"hdg3",
  "west": __DIR__"yaofang",
]));
        set("outdoors", "mingjiao");
        set("objects", ([
                __DIR__"npc/huqn" : 1,
                __DIR__"npc/wangnangu" : 1,
        ]) );

        setup();
        replace_program(ROOM);
}

