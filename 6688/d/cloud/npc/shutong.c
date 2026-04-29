// shutong.c
//write by lysh

inherit NPC;

void create()
{
        set_name("丫鬟", ({ "ya huan","ya","huan"}) );
        set("gender", "女性" );
        set("age", 12);
        set("long",
                "她是张百万的掌上明珠的丫鬟，常要陪小姐读书。她正向窗外看风景呢。\n");
	set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
}

