#include <room.h>

inherit ROOM;

void create()
{
   set("short", "内厅穿堂");
        set("long", @LONG
通过『 垂花门 』便是往后院。垂花门为男女之门限，古来女
人就有「大门不出，二门不迈」的谚语，於是二门堪称为男女门限
。后院为庄内女弟子厢房，与湘园。东面一扇小门，为庄内更衣沐
浴的小花池。更是严禁外人胡乱闯入。
LONG
        );
    set("exits", ([
     "north" :__DIR__"corridor7",
     "east" :__DIR__"bathroom1",
    ]));
    set("objects", ([
        __DIR__"npc/shaoin" : 1,
    ]) );

     create_door("north","垂花门","south", DOOR_CLOSED);
     create_door("east","小帘门","west", DOOR_CLOSED);

        setup();
//        replace_program(ROOM);
}

void init()
{
//	add_action("do_get", "get");
}

int do_get(string arg)
{
	if(arg=="all") {write("这里只能一件件拿。\n");return 1;}
	if(arg=="shaoin" || arg=="shao" || arg=="龙韶吟"){
	write("龙五的身影出现在一阵烟雾之中。\n");
	write("龙五对你大喝一声，欺侮我们龙家的人，想找死啊？\n");
	write("龙五伸手把你的魂魄从体内拽了出来，不知道扔到什么地方去了。\n");
	this_player()->die();
	return 1;
	}
	else
	return 0;
}
