//by meteoric
inherit ROOM;

void create()
{
	set("short", "山谷内");
	set("long", @LONG
山谷内居然别有洞天，这儿稀稀落落散布着几间房子，也有一些田地，田里有一些
正在耕作的农人。炊烟袅袅升起。你可以听见孩童的嘻闹声，狗吠声，这儿的人都满面
红光，脚步轻健，显然都有一身好武艺。
LONG
	);
	set("exits", ([
		"northwest":__DIR__"shidao1",
                "south" : __DIR__"groad3",
	]));
	setup();
	replace_program(ROOM);
}
