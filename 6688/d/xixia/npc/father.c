inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("卖艺老头", ({ "old man", "man" }) );
        set("gender", "男性" );
        set("age", 52);
        set("long", "一个靠卖艺为生的老头。\n");

        set("str", 19);
        set("int", 16);
        set("combat_exp", 55000);
        set("score", 500);

        set("attitude", "heroism");
        set("max_force",330);
        set("force",410);
        set("force_facter",3);
        
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("liuh-ken",50);
        map_skill("unarmed","liuh-ken");

        set("inquiry", ([
                "卖艺" : "小老儿和小女靠此为生,唉。。。情非得已啊！",       
 ]) );

        setup();
        add_money("silver", 4);
        carry_object("/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(3) ) {
                case 0:
                        say( "小老儿初到宝地，还请各位高人多多捧场！\n");
                        break;
                case 1:
                        say( "卖艺老头双手抱拳，团团一揖道：“俗话说『在家靠父母，出门靠朋友』，请各位有钱的捧个钱场，没钱的捧个人场！ \n");
                        break;
                case 2:
                      say( "卖艺老头对女儿说：“女儿啊，给这位"  
                             + RANK_D->query_respect(ob) + "露上一手！” \n");
                        break;
        }
}
