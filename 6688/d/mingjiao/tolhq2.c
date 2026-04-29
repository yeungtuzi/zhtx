//TORJQ1.C

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这里是通往烈火旗的大道。道路开阔，大概可容十人并肩而行。
烈火旗精于使用火药及其他火器。由于昆仑特产黑色的火油，
烈火旗如虎添翼，制成的火器十分霸道。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"tolhq1",
		"southwest" :__DIR__"tolhq3",
	]));

	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}