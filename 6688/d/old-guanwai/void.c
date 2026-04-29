inherit ROOM;

void create()
{
        set("short", "幻境");
	set("no_fight",1);
	set("no_faint",1);
        set("long", @LONG
你有一种奇怪的感觉，可是又说不出。这是一间普通的禅房，每件物品都
似曾相识，可是你怎么也想不起在哪里见过。你感觉仿佛在梦中。朦胧中
一个慈祥的老僧在冲你微笑。
LONG
        );
        set("no_clean_up",1);
        set("exits", ([ 
]));
        set("objects", ([
		CLASS_D("lama")+"/gelun" : 1,
        ]) );
        setup();
}
