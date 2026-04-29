// /d/xizang/class/gold_wh/misc.c

inherit ROOM;

void create()
{
        set("short", "杂役房");
        set("long", @LONG
这里是札什伦布寺杂役们的住处.法王好排场,事事皆想与达赖喇嘛看齐,因此
也雇佣了许多的杂役,打点一应事务.这些人晚上就在这作房子里过夜.
LONG
        );
        set("exits", ([
		"north" : __DIR__"fyard",
]));

        setup();
	replace_program(ROOM);
}
