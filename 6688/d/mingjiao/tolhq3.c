//TORJQ3.C

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大路已经延伸到了尽头，这里气势森严。道路两旁便插红旗，迎风
招展，烈烈生威。红色大门通往烈火旗的大厅。
LONG
	);

	set("exits", ([
		"enter" : __DIR__"lhqdating",
		"northeast" :__DIR__"tolhq2",
	]));

	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}