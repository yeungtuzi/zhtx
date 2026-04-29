// mp1.c
#include <ansi.h>
#include <combat.h>

inherit "/std/char/doomnpc";

string *msg_weapon=({
YEL"这位武林前辈长叹了一声，“罢了，罢了，天意如此啊！\n",NOR,
YEL"“数年前，我不听忠言，执意来乾坤教探宝，却中司空老贼奸计被囚禁于此，”\n",NOR,
YEL"“我本想一死了之，不受魔教之人凌辱，无奈我身怀本派无上神兵，”\n",NOR,
YEL"“本已身负重罪，如何又能让其落入魔教之手？”\n",NOR,
YEL"“多年来我忍辱负重，为的就是等待本派你这样的武功卓绝的后起之秀，”\n",NOR,
HIC"“苍天不负我命，终于让我等到了这一天，好孩子，这把倚天剑今后就交给你了！”\n",NOR,
HIR"“一定要好好珍惜它，记住，‘剑在人在，剑亡人亡！’”\n",NOR,
HIG"“听说我的师姐娩娩后来归隐去了侠客岛，如果有机会的话将来你去找她，”\n",NOR,
HIG"“代我给她老人家请安，但愿她能收你为徒，那将是你一辈子的造化！”\n",NOR,
YEL"“我去了……”\n",NOR,
YEL"“心已静，愿已了，去也去也……”\n",NOR,
YEL"这位武林前辈淡然一笑，永远地闭上了双眼…………\n",NOR,
});


void create()
{
        set_name("武林前辈", ({ "no name", "none"}));

        set("long", "一个满脸是血的怪人，一见你就疯一样扑了过来，\n
                仇恨和懊丧已经完全让他丧失了理智。\n");
        set("gender", "女性");
        set("age", 30);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 80);
        set("con", 20);
        set("int", 50);
        set("elo", 40);
        set("dex", 50);
        set("per", 30);
        set("cor", 50);
        set("cps", 50);

        
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({
                (: perform_action, "sword.tisha" :),
    //            (: exert_function, "jiuyang-shield" :),
        }) );



        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("atman", 4000);
        set("max_atman", 2000);
        set("mana", 4000);
        set("max_mana", 2000);
        set("force",8000);
        set("max_force", 4000);
        set("force_factor", 150);
        set("combat_exp", 8000000);
        set("score", 1000000);
        set("mana_factor", 60);

        set_skill("force", 220);
        set_skill("parry", 220);
        set_skill("dodge", 220);        
        set_skill("literate", 220);
        set_skill("sword",220);
        set_skill("strike",220);

        set_skill("essence-sword", 220);
        set_skill("lighting-sword", 220);
        set_skill("bat-steps", 220);
        set_skill("moni-xinfa", 220);
        set_skill("xuanming-shenzhang", 220);         
        
        map_skill("force", "moni-xinfa");
        map_skill("sword", "essence-sword");
        map_skill("parry","essence-sword");
        map_skill("dodge","bat-steps");
        map_skill("move","bat-steps");
        map_skill("strike","xuanming-shenzhang");
        prepare_skill("strike","xuanming-shenzhang");


        set_temp("apply/armor_vs_force", 200);
        set_temp("apply/armor_vs_spells", 20);
        set_temp("apply/armor", 200);


        create_family("明教", 2, "无名前辈");
        set("title", HIB"乾坤教囚徒"NOR);
        set("nickname",HIR "逝去的辉煌，永世的神伤"NOR);
        setup();

        carry_object("/d/qiankun/obj/weapon/yitian-jian")->wield();
}

void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
        object me, room1;
        if( !ob || !objectp(ob) ) return;
        me = this_object();
        room1 = environment(me);

        if (room1->query("no_fight"))
                room1->set("no_fight", 0);

        if (interactive(ob))
        {
                if(ob->query_temp("mpweapon_win")) return 0;
                command("say 魔教的贼子，拿命来吧！！\n");
//                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        }       

}

void die()
{
       object me,ob,weapon;
       ob=this_object();
       me = query_temp("last_damage_from");
       me->remove_all_enemy();
       ob->remove_all_enemy();
       "/cmds/imm/full"->main(ob,"");

       command("pat "+me->query("id"));
       command("sigh");
       if(me->query_skill("essence-sword",1) > 199) 
       {
       me->remove_all_enemy();
       ob->remove_all_enemy();
        revive();
       "/cmds/imm/full"->main(ob,"");
       command("pat "+me->query("id"));
       command("sigh");
       me->set_temp("mpweapon_win",1);
       remove_call_out("telling_truth");
       call_out("telling_truth", 1, me, 0); 
       }
       else
       {
        "/cmds/imm/full"->main(this_object(),"");
        revive();
        command("heng");
        command("say 你是什么人，怎么到这里来了，看你贼眉鼠眼的，定是魔教恶徒！");
        }
        return;

}

void telling_truth(object who, int stage)
{        
        object weapon = new("/d/qiankun/obj/weapon/yitian-jian");       
        object ob;        
        tell_object(who, msg_weapon[stage]);
        if ( !who || environment(who) != environment() )        return;
        
        if( ++stage < sizeof(msg_weapon) ) 
        {
                call_out( "telling_truth", 1, who, stage );
                return;
        }
                if (who->query_temp("mpweapon_win") && !objectp(ob = present("yitian jian",who) )) 
                {
                weapon->move(who);
                }
                destruct(this_object());

        return;
}

