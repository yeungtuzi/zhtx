// jiading.c 家丁

inherit NPC;

void create()
{
	set_name("家丁", ({ "jia ding", "jia" }));
	set("gender", "男性");
	set("age", 35);

	set("combat_exp", 2000+random(5000));
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", -1);
	setup();
	add("silver",1);
	carry_object("/d/suzhou/npc/obj/qbcloth")->wear();
}
	
