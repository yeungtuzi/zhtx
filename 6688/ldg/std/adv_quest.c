// original from es2
// change by thir in zh

#include <dbase.h>
#include <ansi.h>

string quest_file(string tag) {
        string file;
        file = ("/quest/qlist"+tag);    
        return file;    
}

void give_bonus(object who,mapping quest);
int quest_punish(object who);
int time_period(int timep, object me);

string sysmsg;

int give_quest(string arg)
{
        mapping quest,task;
        object me;
        int fft=2, j, combatexp, timep, r_kar, q_bonus;
        string tag = "1000000";
        int shen = this_object()->query("shen_type");
        int target_shen;
	string *levels = ({
                        "0",
                        "1625",
                        "3125",
                        "6250",
                        "12500",
                        "25000",
                        "50000",
                        "100000",
                        "200000",
                        "400000",
                        "800000",
                        "1600000",
                        "3200000",
                        "6400000",
                        "12500000",
                        "25000000",
        });
        if( !arg 		) fft=2;
        if( arg == "-h"		) fft=4;
        if( arg == "-hh" 	) fft =8;
        if( arg == "-hhh"	) fft = 16;
        if( arg == "-hhhh" 	) fft = 32;
        if( arg == "-x" 	) fft = 500;
        if( arg == "-xx"	) fft = 1000; 
        if( arg == "-xxx"	) fft = 2000;
        if( arg == "-l" 	) fft = 1;
        me = this_player();
	// Let's see if this player is a ghost
        if((int) me->is_ghost())
        {
                write("鬼魂不可要任务．\n");
                return 1;
        }
	// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
        	if( ((int) me->query("task_time")) >  time() )
          	{
          		tell_object(me,this_object()->query("name")+ "说道：上次交给你的任务怎么样了？\n" NOR);
          		return(1);
          	}
          	else
          	{
          		me->set("quest_ok",0);
          		quest_punish(me);
          	}
        }
        else 
        {
        	quest=([]);
        }
        
        combatexp = (int) me->query("combat_exp");
        combatexp = combatexp * fft / 2;
        r_kar = random((int) me->query("kar"));
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
        	if( atoi(levels[j])  <= combatexp )
        	{
                	tag = levels[j];
                        if ( r_kar > 15 && j > 0) tag = levels[j-1];
                        if ( r_kar < 3 && j < (sizeof(levels) -1)) tag = levels[j+1];
                        break;
                 }
        }
        if(random(10)<1) tag = "_common";
	
        if ( shen < 0 ) shen = -1;
        else            shen = 1;
        for( j=0;j<5;j++) {
                task = (quest_file(tag))->query_quest();
                target_shen = task["shen_type"];
                if(target_shen == 999 ) break; 
                // if the same shen type then   
                if (( target_shen>=0 && shen==1)||( target_shen<0 && shen== -1))
                {
                	if(task["quest_type"]=="杀") {
                        	task["quest_type"]="胜";
                        	break;
                    	}
                    	else continue;
                }
                // if diff  shen then break;
                break;    
        }
	// check if find a proper task
        if ( j == 5) {

                tell_object(me,this_object()->query("name")+ "摇了摇头说：现在没有任务，好好练功吧！\n" NOR);
                return 1;
        }

        timep= 360;
        timep = random(timep )+ 600;
        time_period(timep, me);

        if (task["quest_type"] == "寻")
        {
        tell_object(me,"找回『"+task["quest"]+"』给我。\n" NOR);
        sysmsg +="找回『"+task["quest"]+"』。";
        }
	if (task["quest_type"] == "杀")
        {
        tell_object(me,"替我杀了『"+task["quest"]+"』。\n" NOR);
        sysmsg +="杀了『"+task["quest"]+"』。";
        }
	if (task["quest_type"] == "胜")
        {
        tell_object(me,"战胜『"+task["quest"]+"』。\n" NOR);
        sysmsg +="战胜『"+task["quest"]+"』。";
        }
	if (task["quest_type"] == "打探")
        {
        tell_object(me,"替我打探『"+task["quest"]+"』的消息。\n" NOR);
        sysmsg +="打探『"+task["quest"]+"』的消息。";
        }
	

	if( tag != "_common" )
        {
                if( fft < 2)
                {// quest -l 的情况 
                        me->set("quest_ok",0);          
        	}
                else  while( fft > 2 ) 
                        {
                                task["exp_bonus"] += task["exp_bonus"]/5; 
                                fft /= 2;
                        }
        }
        if( task["exp_bonus"] > 200 )  task["exp_bonus"] = 200;
        
	quest["who"]=this_object()->query("id");
	quest["quest"]=task["quest"];
	quest["quest_type"]=task["quest_type"];
	quest["bonus"]=task["exp_bonus"];
	//quest["task_time"]=(int) time()+(int) timep;
	//quest["over_time"]=int 0;
	
	me->set("task_time",(int) time()+(int) timep);
	me->set("over_time",(int) 0);
	me->set("quest",quest);
 	return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        string accepter= this_object()->query("name");
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        tell_object(me,HIW "『嗯 ....』，"+accepter + "沉思了一会儿，说道：\n请在" + time + "内");
        sysmsg = "在" + time + "内";
        return 1;
}

int quest_punish(object who) {
	who->set("quest_ok",0);
        who->delete("quest");
        return(1);

}

int accept_object(object who, object ob)
{
        // 2026-04-30: unused variable commented out
        // int bonus, exp, pot, score,val;
        // 2026-04-30: unused variable commented out
        // string test;
        mapping quest;
        string accepter= this_object()->query("name");
        
        if(!(quest =  who->query("quest"))) return 0;
        if( this_object()->query("id")!= quest["who"])
        {
        	tell_object(who,accepter+"说道：你好像没有从我这儿接受过任务。\n");
        	return 0;
        }
        if( (string)ob->query("name") != quest["quest"])
        {
        	tell_object(who,accepter+"说道：这不是我想要的。\n");
        	return 0;
        }
        if( ob->is_character() ) {
                tell_object(who,accepter+"说道：你想蒙混过关吗!\n");
                return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
        	tell_object(who,accepter+"说道：真可惜！你没有在指定的时间内完成！\n");
                return 1;
        }
        else 
        {
                tell_object(who,accepter+"告诉你：恭喜你！你又完成了一项任务！\n");
                destruct(ob);
                give_bonus(who,quest);
        }
        return 1;
}

void give_bonus(object who,mapping quest)
{
        int gold,a_gold;
        int quest_ok_time;
        object ob;

        gold = quest["bonus"]/50 + random(quest["bonus"]/50)+1;
        quest_ok_time = who->query("quest_ok");
        a_gold=quest_ok_time/5;
        if(a_gold>5) a_gold=5;
        gold = gold+a_gold;
        
        ob = new(GOLD_OB);
        ob->set_amount(gold);
        ob->move(who);
        tell_object(who,HIW"你被奖励了："+chinese_number(gold)+"两金子\n" NOR);
                
        who->add("quest_ok",1);
        
        who->delete("quest");
	who->set("over_time",(int) 0);
        return;
}

