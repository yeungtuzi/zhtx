//LHQPAIFANG.C

inherit ROOM;

void create()
{
	set("short", HIY"光明顶"NOR);
	set("long", @LONG
	穿过牌坊，是一片极为宏大的广场，遍插五色旗帜，好似
烈焰蒸腾，红雾遍野，实在是江湖中一般门派所没有的壮观景象。
由此向东北折转，大路直通锐金旗；由此向西北而行，则为巨木旗。
西南方向是烈火旗，东南是厚土旗。五行旗承相生相克之势，拱卫
光明顶。向北是一条宽阔的汉玉石阶，两侧齐刷刷站立两排教众，
石阶的尽头是一座宏伟的大殿。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"torjq1",
		"northwest" :__DIR__"tojmq1",
		"northup" : __DIR__"guangmingding",
		"southwest" : __DIR__"tolhq1",
		"southeast" : __DIR__"tohtq1",
		"southdown" : __DIR__"lhqpaifang",
	]));

	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}