// /obj/npc/s_wolf.c

inherit NPC;

void create()
{
        set_name("小狼", ({"small wolf", "wolf" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只尚未成年的狼崽子.\n");
        
        set("str",13);
        set("cor",30);
        set("cps",13);

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set("max_kee",1000);
        set("attitude","aggressive");
        set("combat_exp",10000);
        set("bellicosity",1000);
       
        set_temp("apply/attack",20);
        set_temp("apply/armor",20);
        set_skill("dodge", 80);
        
        setup();
}

