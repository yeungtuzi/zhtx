#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("唐梦", ({ "tang meng", "meng" }));
        set("nickname", HIC"妙手毒王"NOR);
        set("long", 
"   他是唐门门主的哥哥，现任唐门总护法，负责保护唐门的安全,\n"
"维护唐门的声誉。少年时代在外游历，14 岁回到家中聆听老母欧阳\n"
"氏敏夫人的教诲，终成江湖一代名侠，被誉为妙手毒王。一生坎坷，\n"
"命运多厄，常自孤独难眠，以“梦里幽情总伤心”，“心伤心流泪，\n"
"梦醒梦难回 ”等自勉。中年时，终心灰意冷，带着一身深不可测的\n"
"武功和一脸憔悴落寞的神情回到唐门担任起保家重任。\n");

        set("gender", "无性");
        set("age", 50);
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
                set_skill("literate", 300);
                set_skill("force", 220);
                set_skill("tangmen-xinfa", 220); 
                set_skill("move", 220);
                set_skill("dodge", 220);
                set_skill("claw", 220);
                set_skill("parry", 220);
                set_skill("yin-gong", 240);
                set_skill("dugong",250);
                set_skill("tangshi-jian", 220);
                set_skill("mantian-huayu", 220);
                set_skill("throwing", 220);
                set_skill("sword", 220);
                set_skill("strike", 220);
                set_skill("tangmen-duzhang", 220);
                set_skill("taxue-wuhen", 220);
                set_skill("unarmed", 100);
                set_skill("kuihua-shengong", 220);
                set_skill("mo-zhang-jue", 200);
                set_skill("mo-jian-jue", 190);
                set_skill("pixie-sword", 220);
                set_skill("daguanming",150);

                map_skill("force", "yin-gong");
                map_skill("dodge", "yin-gong");
                map_skill("move", "yin-gong");
                map_skill("claw", "yin-gong");
                map_skill("throwing", "mantian-huayu");
                map_skill("sword", "tangshi-jian");
                map_skill("strike", "tangmen-duzhang");


        create_family("唐门", 2, "副门主");
        set("title",HIB "唐门" NOR + HIG "副门主" NOR);
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

        if( (int)ob->query_skill("dugong",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                 +"毒功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query_skill("force",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"内功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 好孩儿，你这么争气。。。");
                command("say 那为师这就收下你了，以后一定要勤加修炼，光大我全真派！！");
                command("say 驱逐鞑子，光复中华！！");
                command("recruit " + ob->query("id") );
                ob->add("wlshw",-50);
                ob->set("title",HIY"唐门"+HIG"阴功护法"NOR);
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "legend");
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



