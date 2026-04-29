// /d/xizang/bridge.c

inherit ROOM;

void create()
{
        set("short", "铁索桥");
        set("long", @LONG
这是一道摇摇晃晃的铁索桥,高架在波涛汹涌的雅鲁藏布江上.站在桥上往下
看去,江流奔腾澎湃,浪花飞溅,令人头晕目眩.
LONG
        );
        set("exits", ([
        "north" : __DIR__"river",
	"south" : __DIR__"s_bank",
]));
        set("objects", ([
                __DIR__"npc/somebody" : 1,
]) );
	set("outdoors", "xizang");
        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (me->query_skill("dodge") < 50)
	message_vision("$N站在摇摇晃晃的铁索桥上,不敢轻易挪动脚步\n", me);
	me->start_busy(2);
	return 1;
}
