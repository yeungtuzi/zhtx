// sheepgirl.c

inherit NPC;

void create()
{
        set_name("牧羊人", ({ "sheep boy", "boy" }) );
        set("gender", "男性" );
        set("age", 17);
        set("long", "一个天真活泼，英俊好客的小伙子。 \n");
        set("per", 30);
        set("attitude", "friendly");
        set_skill("whip", 90);
        set_skill("parry", 50);
        set_skill("dodge", 70);
        set_skill("force", 60);
        set("combat_exp",25000);
        set("score",-530);
        setup();

        add_money("coin", random(80));
        carry_object(__DIR__"obj/sheepwhip")->wield();
        carry_object(__DIR__"obj/sheepcloth")->wear();
}
