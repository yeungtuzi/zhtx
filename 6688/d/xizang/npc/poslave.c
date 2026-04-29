// /d/xizang/npc/poslave.c

inherit NPC;

void create()
{
        set_name("波斯奴", ({ "bosi slave", "slave"}) );
        set("gender", "男性" );
        set("age", 20+random(12));
        set("long", "这是一位红发碧眼，高达六尺的蕃人。\n");
        set("combat_exp", 50000+random(10)*5000);
        set("bellicosity", 3000 );
        set("attitude", "aggressive");
        set_skill("blade", 90);
        set_skill("dodge", 100);
        set_skill("parry", 20);
//        set("iron-cloth", 20);

        setup();
        add_money("coin", 50);
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/roundblade")->wield();
}
