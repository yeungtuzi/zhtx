// Room: /u/cloud/wroad1.c

inherit ROOM;

void create()
{
        set("short", "绮云镇街道");
        set("long", @LONG
东边青板石铺的路与向西的碎石小径在这里汇合。西面仿佛是座庄
院，但现在路已经不通了; 南面是家私塾; 北面是红娘庄，常常
有一对对男女来往。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"marry_room",
                "south" : __DIR__"bookstore",
                "east" : __DIR__"wroad2",
        ]));
        set("outdoors", "cloud");
	set("objects", ([
                "/adm/npc/zhuting" : 1,
        ]) );

        setup();
        replace_program(ROOM);
}

