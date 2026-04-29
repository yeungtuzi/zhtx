#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("龙象", ({ "long xiang","banruok"}) );
        set("long",@LONG
他是纵横天下里一位不世出的英雄。他的身世和不知火舞一样凄惨，自幼沦为
孤儿，从小就在西藏拉萨城里的铁匠铺里当小学徒，依靠打铁为生。终日的辛
苦劳作并没有使他消沉，反而造就了他的一身神力。当金轮法王在中原争夺武
林盟主不成而溃败而归，门下弟子东逃西散的时候，在途中遇上了龙象破例收
他为徒传授之无上密宗心法——龙象般若功，以及其成名绝技五行轮和金刚不
坏功。天赋禀异的他真有似如鱼得水，靠着一身的硬功和掌中的五行金轮横行
天下。他名为金轮法王之徒，但实际上已是西藏喇嘛教的中流砥柱，中原武林
皆因为龙象大喇嘛而不敢轻视西藏。后在机缘巧合中与不知火舞结为伉俪，联
合天下诸派英雄扫平了幽明山庄和接天楼，从而获得了极高的武林威望，至此
之后，天下武功尽为其所取，为其所用，至其不惑之年时，已然尽悉天下武学
之精华，成为当时统领武林的中坚力量。
LONG
         );

        set("title",HIG"绝版菜鸟"NOR);
        create_family("大招寺", 1, "监寺");

        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("cor", 100);
        set("int", 100);
        set("spi", 100); 

        set("cps", 100); 
        set("per", 50);
        set("con", 100);
        set("kar", 100);
        set("bln", 100);

        set("kee", 5000);
        set("max_kee", 5000);
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
        set("mana_factor", 150);
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
        set_skill("hammer", 200);
        set_skill("sword", 200);
        set_skill("strike", 200);
        set_skill("iron-cloth", 200);
        set_skill("mingwang-jian", 200);
        set_skill("essence-sword", 200);
        set_skill("lighting-sword", 150);
        set_skill("bat-steps", 200);
        set_skill("moni-xinfa", 200);
        set_skill("xuanming-shenzhang", 200);   
        map_skill("force", "bolomiduo");
        map_skill("unarmed", "bloodystrike");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");
        map_skill("hammer", "wuxinglun");
        map_skill("strike", "nutrifux");
        map_skill("sword", "mingwang-jian");

        map_skill("magic", "essencemagic");

        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   


      



        setup();

//    carry_object("/d/qiankun/obj/weapon/zijinchui")->wield();


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
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( random(10) < 2)
        {
                say("这位" + RANK_D->query_respect(ob)
                  +"知道我的转世是谁吗？据说是当今天神呢，但他成天无所事事，看来在位时间不会太长......\n");
        }
        else
        if( random(10) > 8)
        {
                say("哎，" + RANK_D->query_respect(ob)

                 +"帮我监督着点一点红这个破人，别让他违法乱纪犯错误，不然又是一瓶小二！\n");
        }
        else if (random(2) >0 )
        {
                command("hmm " + ob->query("id"));
        }
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
        if( !ob->query("got_ling") ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"怎么跑到这侠客岛上来的，这里还不是你能来的地方！！");
                return;}
        if( !ob->query("mpweapon_got") ){
                command("say 本派神兵在江湖上已经失落多年，你如果能找到它我就收你为徒。");
                return;}
      if( (int)ob->query_skill("force",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"基本内功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
      if( (int)ob->query_skill("zang-buddhi",1) < 300 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"藏传佛法修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("combat_exp") < 12800000 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"江湖经验还不够丰富，还需回去多点历练，否则不配做我的弟子。");
                return;}
        if( (int)ob->query_skill("iron-cloth",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"硬功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}

        else {
                command("say 好孩子，为师就收下你了！");
                command("say 在江湖上混一定要守规矩，胡来是不行的，不要哪天怎么死的都不知道！");
                command("recruit " + ob->query("id") );
                ob->add("wlshw",-50);
                ob->set("title",HIY"大招寺"+HIG"转世"+HIW"活佛"NOR);

        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
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

void die()
{      
        unconcious();
        "/cmds/imm/full"->main(this_object(),"");
        revive();
        command("heng");
        command("say 你以为你谁啊，真是找死！");
        command("rascal long xiang");
        command("heihei"); 
        return;
}

