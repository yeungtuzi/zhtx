inherit NPC;

void create()
{
        set("long",@LONG
一个全副武装的骑兵，跨在一匹高头大马上，说不出的威风。
LONG);
        set_name("骑兵",({"knight"}) );
        set("gender","男性");
        set("age",20+random(20));

        set("str",35);
        set("cor",24);
        set("int",24);
        set("spi",23);
        set("cps",30);
        set("con",25);

        set("max_force",500);
        set("force",500);

        set("max_kee",1800);
        set("force_factor",30);

	set("shen_type", -1);
        set("attitude","peaceful");
        
        set("combat_exp",200000 + random(20000));

	set_temp("apply/attack", 40);
	set_temp("apply/damage", 40);

        set_skill("force",60);
        set_skill("xiaowuxiang-gong",60);
        set_skill("dodge",80);
        set_skill("parry",120);
        set_skill("blade",120);

        map_skill("force","xiaowuxiang-gong");

        setup();
        carry_object(__DIR__"obj/steel_blade")->wield();
        carry_object(__DIR__"obj/steel_armor")->wear();
	carry_object(__DIR__"obj/steel_head")->wear();
	carry_object(__DIR__"obj/feather_shoe")->wear();
}
