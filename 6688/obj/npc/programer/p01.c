#include <ansi.h>
inherit NPC;

string open_game();
string ask_post();
string close_game();

void create()
{
        object ob;
        set_name(HIC"纵横活动员MM"HIR" NO.1"NOR, ({ "programer 01","programer"}) );
        set("gender", "女性" );
        set("age", 200);
        set("long","纵横活动员MM NO.1\n");
        set("combat_exp", 5000000);
        set("start_mark", "N");
        set("inquiry",([
                                "开始比赛"  :(:open_game:),
                                "报名"      :(:ask_post:),
                                "结束比赛"  :(:close_game:),                            
                                "B" : "B",
        ]));

        carry_object("/obj/cloth")->wear();
        setup();
}

string open_game()
{
        object me = this_player();
        
        if(!wizardp(me)) return "对不起，你没有资格开始活动！\n";
        
        if(query("start_mark") == "Y") return "比赛已经开始！\n";
        
        set("start_mark", "Y");
        
        message("channel:chat",
                HIY + "\n【纵横活动】" + name() + 
                HIY"(" + capitalize(query("id")) + ")：" +
                "纵横新村首届龟兔赛跑比赛现在开始，请大家踊跃报名！\n\n"+NOR,users());
}

string ask_post()
{
        object me = this_player();
        
        //if(wizardp(me)) return "巫师不能参加玩家活动！\n";
        if(!wizardp(me)) return "本活动暂时未开放！\n";
        
        if(query("start_mark") == "Y")
        {
                if( me->query("mud_age") > 300)
                        return "您的年龄不符合参加比赛的要求！\n";
                
                if( me->query("pgm/01"))
                        return "您已经报名过了，请抓紧时间比赛！\n";
                        
                me->set("pgm/01", 1);
        
                message("channel:chat",
                        HIY + "【纵横活动】" + name() + 
                        HIY"(" + capitalize(query("id")) + ")：" +
                        me->name() + " 报名参加纵横新村龟兔赛跑比赛，请大家为他加油！\n"+NOR,users());
        }
        else return "对不起，本活动只有在周末才对玩家开放，请耐心等待！\n";
}

string close_game()
{
        object me = this_player();
        
        if(!wizardp(me)) return "对不起，你没有资格结束活动！\n";
        
        if(query("start_mark") == "N") return "活动已经结束！\n";
        
        set("start_mark", "N");
        
        message("channel:chat",
                HIY + "\n【纵横活动】" + name() + 
                HIY"(" + capitalize(query("id")) + ")：" +
                "纵横新村首届龟兔赛跑比赛圆满结束，下面公布比赛成绩和奖励！\n\n"+NOR,users());
}

