// /d/xizang/class/budala/ustair1.c
inherit ROOM;

void create()
{
        set("short", "台阶");
	set("long", @LONG
这里是布达拉宫前殿后的台阶,通往断事司.藏边府实行政教合一制,大活佛
同时亦是最高行政长官,但是通常不亲自处理政务,而是委托一名断事官代理.达
赖喇嘛的代表就在断事司办公,藏边府的一般公务由他就可以解决.
LONG
        );
        set("exits", ([
		"northup" : __DIR__"duan",
	      "southdown" : __DIR__"fhall",
]));
        set("outdoors", "xizang");
	setup();
        replace_program(ROOM);
}
