// /d/xizang/class/dazhao/npc/lingbao.c

inherit NPC;

void create()
{
	set_name("灵宝上人", ({ "lingbao shangren", "lingbao", "shangren" }));
	set("gender", "男性" );
	set("age", 46);
	set("int", 35);
        create_family("大招寺", 33, "弟子");
	set("long","他是班禅大师的弟子之一.\n");
        set("combat_exp", 199999);
        set("score", 9000);
	set("shen", -1000);
	set("force", 1000);
	set("max_force", 500);
	set("mana", 1000);
	set("max_mana", 500);
	set("atman", 1000);
	set("max_atman", 500);
        set_skill("unarmed", 50);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 50);
	set_skill("magic", 50);
	set_skill("bolomiduo", 140);
	set_skill("zang-buddhi", 140);
	set_skill("bloodystrike", 100);
//	set_skill("essencemagic", 300);

        map_skill("force", "bolomiduo");
	map_skill("unarmed", "bloodystrike");
//      map_skill("literate", "zang-buddhi");
//      map_skill("magic", "essencemagic");
	
	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
}
