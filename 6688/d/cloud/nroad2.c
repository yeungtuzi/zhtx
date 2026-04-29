// Room: /u/cloud/nroad2.c

inherit ROOM;

void create()
{
        set("short", "南市场");
        set("long", @LONG
这里是绮云镇的南市场，西面是杂货铺，向东可看到 怡红院 的二楼。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zaihuoy",
  "north" : __DIR__"nroad1",
  "south" : __DIR__"cross",
]));
        set("outdoors", "cloud");

        set("objects",([
		"/class/gaibang/ma-jw":1,        
        ]));


        setup();
        replace_program(ROOM);
}

