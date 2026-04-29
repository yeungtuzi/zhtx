
inherit NPC;

void create()
{
        set_name("幽冥大鹏", ({ "death roc" }) );
        set("race", "野兽");
        set("age", 25);
        set("long", "一只外形十分凶猛的大鹏鸟。\n");
        
        set("str",100);

        set("limbs", ({ "头部", "身体", "尾巴" }) );

	set("max_kee",3000);
        set("combat_exp",3000000);
	set("max_force",2000);
	set("force",4000);
	set("force_factor",100);
      
        set_temp("apply/attack",80);
        set_temp("apply/armor",80);

	set_skill("force",200);
        set_skill("dodge", 500);
	set_skill("throwing",200);        
	set_skill("roc_throwing",200);        

	map_skill("throwing","roc_throwing");

	set("shen_type",-1);
	set("shen",10000000);          
	set("env/invisibility",1);
        setup();             

	carry_object(__DIR__"obj/duzhen")->wield();
}

