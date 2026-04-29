// /d/xizang/class/bad/npc/waner.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("绾绾", ({ "waner", "wan wan", "wan" }));
	set("title", YEL+"武当女真人"+NOR);
	set("gender", "女性" );
	set("age", 25);
	set("str", 28);
	set("cor", 30);
	set("cps", 29);
	set("int", 27);
	set("per", 29);
	set("long", @TEXT
她是武当弟子绾绾,白道三位著名侠女之一,也是桃花岛小仙女最好的朋友
TEXT
);
	set("combat_exp", 2400000);
	set("attitude", "heroism");
	set("force", 4500);
        set("max_force", 4500);
        set("force_factor", 150);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("dodge", 180);
	set_skill("sword", 230);
	set_skill("force", 199);
	set_skill("taiji-jian", 260);
	set_skill("taiji-quan", 155);
        set_skill("taiji-shengong", 199);
        set_skill("move", 199);
        set_skill("tiyunzong", 219);
	map_skill("sword", "taiji-jian");
        map_skill("parry", "taiji-jian");
        map_skill("unarmed", "taiji-quan");
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("move", "tiyunzong");
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangjian")->wield();
}

//add helping 
