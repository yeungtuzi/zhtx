inherit NPC; 

void create()
{
        set_name("青衣家人",({ "qingyi jiaren","jiaren","jia ren" }) );
        set("gender", "男性" );
        set("age", 25);
        set("long", "他是明教后院的小厮，平时干些仆役的工作。\n");
//      set("shen", -100);
        set("shen_type", 1);
        set("str", 15);
        set("dex", 18);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 200);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);
        set("attitude", "peaceful");
        setup();
        carry_object("/obj/cloth")->wear();
}
                                