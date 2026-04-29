// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "月观峰");
	set("long", @LONG
这里是位于南天门西面的山岭，怪石攒簇，最高的地方一石
卓立，名为君子峰。往北走便是泰山的西天门。
LONG
	);

	set("exits", ([
		"westup" : __DIR__"yuhuang",
		"eastup" : __DIR__"tanhai",
	]));
        set("no_fight",1);
        set("no_death",1);
        set("no_magic",1);

        set("objects", ([ 
  "/d/taishan/npc/referee":1,
	"/d/snow/obj/bamboo_sword":2,
	"/d/resort/obj/bblade":2,
          "/d/guanwai/obj/junkstaff":2,
]));


	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

