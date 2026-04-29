// monk_guard.c

inherit NPC;

void create()
{
	set_name("水烟阁武士", ({ "waterfog guard", "guard" }) );
	set("gender", "男性" );
	set("age", 25);
	set("str", 30);
	set("cor", 30);
	set("cps", 22);
	set("int", 16);
	set("per", 20);
	set("spi", 22);
	set("kar", 22);
	set("con", 24);
	set("long", @LONG
    这个人相貌十分魁梧。
LONG
);
	set("attitude", "heroism");

        set("atman", 300);
        set("max_atman", 300);

        set("force", 500);
        set("max_force", 500);
        set("force_factor", 4);

        set("mana", 100);
        set("max_mana", 100);

        set("combat_exp", 10000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        
                
        set_skill("unarmed", 40);
        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("celestrike", 20);
        set_skill("celestial", 30);
        
        map_skill("unarmed", "celestrike");
        map_skill("force", "celestial");
               

	set("shen_type",-1);
	setup();

        carry_object("/d/waterfog/npc/obj/crimsonsuit")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="fighter" )
                command("say 你还回去好好练练再来吧");
        else
                command("say 敢到天邪来撒野, 你去死吧");
	return 1;
}

