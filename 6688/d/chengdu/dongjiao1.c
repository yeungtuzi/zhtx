
inherit ROOM;

void create()
{
	set("short", "东郊");
	set("long", @LONG
	出了成都的东门，远离了那一片喧闹的繁华，你顿时觉得心神一畅，迎
面阵阵轻风吹拂，送来淡淡的花香，你不禁放慢了脚步，流连于这一片净土之中.
南面是一座清雅的尼庵。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
			"west" : __DIR__"dongmen",
			"southeast" : __DIR__"dongjiao2",
			"south" : __DIR__"miaoxiangan",
	]));

	setup();
	replace_program(ROOM);
}

