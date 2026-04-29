#include <ansi.h>
inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;

object suit;
string suitname;
string *suit_name =
({
        HIW"之袍"NOR,
        MAG"魔导衣"NOR,
        GRN"轻带"NOR,
        CYN"逍遥巾"NOR,
        RED"之冠"NOR,
        YEL"疾风靴"NOR,
});

void create()
{
        setup();
}

void init()
{
  add_action("give_quest","quest");
  return ::init();
}

void attempt_apprentice(object ob)
{
        if(this_player()->query("family/family_name")!="日月神教")
         {
                  write( RANK_D->query_respect(this_player()) +
                        "还是请回吧!我不收教外之人\n");
                  return;       
         }
        if( this_player()->query_skill("tianmo-dafa",1) < 100 )
        {
                command("say 你的功力不够，不能拜师。\n");
                return;
        }
        command("say 你日后必有大成。\n");
        command("recruit " + ob->query("id"));
        if( ob->query("gender") == "女性" )
        {
                ob->set("title",CYN"日月"+MAG "神教" GRN + "魔女"NOR);
                ob->set("rank_info/respect","圣姑");
                ob->set("marks/帮派","圣");
                ob->set("marks/圣","  姑 ");
        }
        else
        {
                ob->set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "长老");      
                ob->set("rank_info/respect","神魔");
                ob->set("marks/帮派","神");
                ob->set("marks/神","  魔 ");
        }
        return; 
}
int chat()
{       
       if( is_fighting() && query("kee")<query("max_kee")/5 && !is_busy() && !query_temp("prepare_armageddon"))
        {
                set_temp("apply/defense",300);
                message_vision(HIR"$N喝道：今天"+RANK_D->query_self_rude(this_object())+"跟你们拼了！\n"NOR,this_object());
        }
        if( query("force")<query("max_force")*2 && !random(6) ) add("force",1000);
        return ::chat();
}       
