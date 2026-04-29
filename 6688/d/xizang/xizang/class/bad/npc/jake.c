// /d/xizang/class/bad/npc/jake.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("驱魔金刚", ({ "jake", "qu mo jingang", "jinguang" }));
	set("title", MAG+"大招寺总护法"+NOR);
	set("gender", "男性" );
	set("age", 57);
	set("str", 45);
	set("cor", 33);
	set("cps", 29);
	set("int", 23);
	set("long", "他是奉班禅大师之命前来扫平恶人谷的大招总护法驱魔金刚\n");
	set("combat_exp", 2400000);
	set("attitude", "heroism");
	set("force", 4000);
	set("max_force", 4000);
	set("force_factor", 250);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 99);
	set_skill("force", 200);
	set_skill("bolomiduo", 300);
	set_skill("staff", 300);
	set_skill("cloudstaff", 300);
	set_skill("bloodystrike", 200);
	set_skill("iron-cloth", 299);
	set_skill("jin-gang", 279);

	map_skill("staff", "cloudstaff");
	map_skill("parry", "cloudstaff");
	map_skill("force", "bolomiduo");
	map_skill("unarmed", "bloodystrike");
	map_skill("iron-cloth", "jin-gang");
	set("chat_chance", 15);
        set("chat_msg", ({
                (: this_object(), "random_move" :)
        }));
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	carry_object(OBJ_DIR"weapon/gangzhang")->wield();
}
