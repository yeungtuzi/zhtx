// /d/xizang/class/bad/hall.c

inherit ROOM;

void create()
{
	set("short", "唯我独尊堂");
	set("long", @LONG
这就是十大恶人议事的唯我独尊堂,虽然陈设简陋,但是屋宇高大,气度不凡.尽
管说是议事之用,堂名却叫作唯我独尊,显然除了这里的主人道可道, 其他人只怕
也没多少说话的机会.
LONG
);
	set("exits", ([
		"north" : __DIR__"road6",
	]));
	set("objects", ([
		__DIR__"npc/dao" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
