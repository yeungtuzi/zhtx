#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("娩娩", ({ "wan wan", "waner" }));
        set("nickname", HIG"大猪头"NOR);
        set("long", 
"   待续....\n");

        set("gender", "女性");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("cor", 100);
        set("int", 100);
        set("spi", 100); 

        set("cps", 100); 
        set("per", 100);
        set("con", 100);
        set("kar", 100);
        set("bln", 100);

        set("kee", 10000);
        set("max_kee", 10000);
        set("gin", 5000);
        set("max_gin", 5000);
        set("sen", 5000);
        set("max_sen", 5000);
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 300);
        set("atman",8000);
        set("max_atman", 4000);
        set("mana", 8000);
        set("max_mana", 4000);
        set("combat_exp", 20000000);
        set("score", 200000);

        set("apprentice_available", 3);
        set_skill("literate", 200);
        set_skill("magic", 200);
        set_skill("zang-buddhi", 300);
        set_skill("essencemagic", 200);
        set_skill("space", 200);
        set_skill("notracesnow", 200);
        set_skill("yujiamu-quan", 200);
        set_skill("wuxinglun", 200);
        set_skill("jin-gang", 200);
        set_skill("banruo", 200);
        set_skill("bloodystrike", 200);
        set_skill("bolomiduo", 200);
        set_skill("cloudstaff", 200);
        set_skill("nutrifux", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);
        set_skill("staff", 200);
        set_skill("moni-xinfa",200);
        set_skill("hammer", 200);
        set_skill("essence-sword", 200);
        set_skill("lighting-sword", 150);
        set_skill("bat-steps", 200);
        set_skill("moni-xinfa", 200);
        set_skill("xuanming-shenzhang", 200);         
        set_skill("sword", 200);
        set_skill("strike", 200);
        set_skill("iron-cloth", 200);
        set_skill("mingwang-jian", 200);
        map_skill("force", "moni-xinfa");
        map_skill("unarmed", "bloodystrike");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");
        map_skill("hammer", "wuxinglun");
        map_skill("strike", "nutrifux");
        map_skill("sword", "essence-sword");


        create_family("明教", 2, "圣女");
        set("title",HIG "明教" NOR + HIC "圣女" NOR);
        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );        

        setup();
//    carry_object("/d/qiankun/obj/weapon/tiandunshenjian")->wield();

}


void init()
{
        object ob;
        ob = this_player();     
        ::init();
        if( interactive(ob) && !is_fighting() )
               {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        add_action("give_quest","quest");
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 我今天已经收了三个弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
        object me  = this_object();

        mapping ob_fam;
        // 2026-04-30: unused variable commented out
        // mapping my_fam  = me->query("family");
         if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "明教")
        {
                 command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？

");
                return 0;
        }

        if (ob->query("gender")!="女性") {
                command("say 我只收女弟子，阁下可以拜飞雪。");
                return 0;
        }
  
        if( !ob->query("got_ling") ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"怎么跑到这侠客岛上来的，这里还不是你能来的地方！！");
                return;}
        if( !ob->query("mpweapon_got") ){
                command("say 本派神兵在江湖上已经失落多年，你如果能找到它我就收你为徒。");
                return;}
        if( (int)ob->query("combat_exp") < 12800000 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"江湖经验还不够丰富，还需回去多点历练，否则不配做我的弟子。");
                return;}

        if( (int)ob->query_skill("sword",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"剑法修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 好孩儿，你这么争气。。。");
                command("say 那为师这就收下你了，以后一定要勤加修炼，光大我明教！！");
                command("recruit " + ob->query("id") );
                ob->add("wlshw",-50);
                ob->set("title",HIG"明教"+HIC"圣女使者"NOR);
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        add("apprentice_availavble", -1);
}


// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什-
么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真-
笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}



