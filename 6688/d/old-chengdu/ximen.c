

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "西门");
	set("long", @LONG
	这里是成都的西城门，出了这道门就基本脱离了朝廷势力的笼罩了，这里
的官兵们戒备格外地森严，动不动就截住行人盘问。一条笔直的青石板大道向东西
两边延伸。西边是郊外，武林中神秘而可怕的唐门据说就在西南方向.不远处耸立着
一座高楼。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"southwest" : __DIR__"zhangyilou",
		"east" : __DIR__"xidajie1",
  		"west" : "/d/road/rcdtojs0", // 这里接上原来的路
	]));
        set("objects", ([
                "/obj/npc/wujiang10" : 1,
                "/obj/npc/bing" : 2,
        ]));
	setup();
}

