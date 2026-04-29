// Room: /class/qingcheng/nankou1.c

inherit ROOM;

void create()
{
	set("short", "[33m福州南门[2;37;0m");
	set("long", @LONG
这里已经到了福州南门了.往北就是福州新发展的城区.南边有一条
小河蜿蜒曲折的向东流去.人们在靠近小河的地方打了一口井(well),方
便过往商贾游人灌水歇息.
LONG
	);
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
]));
	set("item_desc", ([ /* sizeof() == 1 */
		"well" : "井里的水非常的清澈,在这里洗把脸,灌满水再赶路该有多好!
",
]));
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"port",
		"north" : __DIR__"jie41",
		"southwest" : __DIR__"bridge",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
