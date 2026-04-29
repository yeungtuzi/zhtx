// wraith.c

inherit "/std/char/doomnpc";

int is_ghost() { return 1; }

void create()
{
	set_name("翁四先生的厉鬼", ({ "wraith" }) );
	set("long",
		"一个披头散发，浑身是血的厉鬼，正在这里飘来飘去。\n" );

	set("max_gin", 2000);
	set("max_kee", 4000);                    
	set("max_sen", 2000);
	set("max_force",4000);
	set("force",8000);
	set("force_factor",150);
	set("bellicosity",50000);
	set("cor",30);
      set("combat_exp",5000000+random(5000000));

	set_skill("unarmed", 180);
	set_skill("dodge", 180);
	set_skill("xiaoyaoyou",200);
	set_skill("parry", 180);
	set_skill("move", 300);
	set_skill("staff",180);
	set_skill("dagou-bang",180);

	map_skill("staff","dagou-bang");
	map_skill("parry","dagou-bang");
	map_skill("dodge","xiaoyaoyou");
	map_skill("move","xiaoyaoyou");

	set_temp("apply/attack",50);

	set("chat_chance_combat",5);
        set("chat_msg_combat", ({
                "还..我..命..来...\n",
        }) );

	set("shen_type",-1);
	set("shen",1000000);
	setup();

	carry_object(__DIR__"obj/gangguai")->wield();

}
