// /obj/npc/teacher.c
// here's a special teacher for exams

#include <skill.h>
#include <ansi.h>
inherit NPC;

string ask_me();
string * list_string;
string room_short, school_name;
object who, room;

void create()
{
	set_name("老师", ({ "teacher", "laoshi", "man" }) );
        if(random(10)<5)
            set("gender", "男性" );
        else
            set("gender", "女性" );
	set("age", 22 + random(41) );
        set("long","这是一位看起来精明干练的老师.\n");
	set("combat_exp", 20000+20*random(100));
	set_skill("literate", 60+random(60));
        set("inquiry", ([
                "报名" : (: ask_me :),
                "考试" : (: ask_me :),
                "报考" : (: ask_me :),
                "升学" : (: ask_me :),
                "毕业" : (: ask_me :),
        ]) );
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_list", "list");
        if (!objectp(room=environment(this_object()))) {
                write("把我搬到什么地方来了?!\n");
                return;
                }
        if (!living(this_object()) || !living(who=this_player()) ) {
                write("现在你显然无法和这位老师交谈.\n");
                return;
                }
        room_short = room->query("short");
}

string ask_me()
{
        return "请用list命令列出我可以帮你做的事情.\n";
}

int do_list(string arg)
{
        string temp;
        int i;

        switch(room_short) {
                case "北大招生办" :
                        list_string = SCHOOL_D->query_list("北大");
                        school_name = "北京大学";
                        break;
                case "清华招生办" :
                        list_string = SCHOOL_D->query_list("清华");
                        school_name = "清华大学";
                        break;
                case "桑桑学院总办" :
                        list_string = SCHOOL_D->query_list("桑桑");
                        school_name = "桑桑学院";
                        break;
                default:
                        if (sscanf(room_short, "%s办公室", temp)==1) {
                        say("这里是"+room_short+
                                ",毕业考试或答辩请用(exam)命令.\n");
                        remove_action("do_exam", "exam");
                        add_action("do_exam", "exam");
                        } else 
                        say("这里是"+room_short+",这位同学有什么事儿吗?\n");
                        return 1;
        }
        if (who->query("school/level")=="高中") {
        command("say \t\t你可以报考:\n");
        for (i=0; i<sizeof(list_string); i++) {
                temp = sprintf("\t\t%d\t%s\n", i, list_string[i]);
                say(temp);
                }
        say("请选择(select)你想要的项目.\n");
        remove_action("do_select", "select");
        add_action("do_select", "select");
        return 1;
        } else return notify_fail("只有高中生才可以考大学.\n");
}

int do_select(string arg)
{
        string temp;
        int i, j;

        if (!arg || sscanf(arg, "%d", i) !=1)
                return notify_fail("选择错误,正确用法是:select <数字>\n");
        j = sizeof(list_string);
        if ((i<0) || (i>j)) 
                return notify_fail("选择错误,没有你要的项目!\n");
        temp = list_string[i];
        say("你的选择是\t"+temp+".\n");
        say("请回答(answer)<是(Yes)>确认,或<否(No)>重新选择.\n");
        remove_action("do_select", "select");
        remove_action("do_answer", "answer");
        add_action("do_answer", "answer");
        who->set_temp("answer", temp);
        return 1;
}

int do_answer(string arg)
{
        string temp;
        if (!who->query_temp("answer")) 
                return notify_fail("请先选择(select)你要的项目.\n");
        if (!arg || (arg =="")) 
        return notify_fail("用法:answer <yes | no>\n");
        if ((arg == "y") || (arg == "Y") || (arg == "yes") || (arg == "YES")
                || (arg == "是")) {
        temp = (string)who->query_temp("answer");
        say("你的选择是\t"+temp+".\n");
        who->set("school/attempt", temp);
        who->set("school/attsch", school_name);
        say("请交100元报名费,然后持准考证参加考试.\n");
        who->set("marks/e_exam", 1);
        return 1;
        }
        say("改变主意了?那么请重新选择(select).\n");
        who->delete_temp("answer");
        add_action("do_select", "select");
        return 1;
}

int do_exam(string arg)
{
        string temp;
        temp = who->query("school/major");
        if ((temp!=room_short) && ((temp+"系") != room_short) 
                && ((temp+"所") != room_short) 
                && ((temp+"学院") != room_short)
                && ((temp+"中心") != room_short) )
        return notify_fail("你不能在这里要求考试或答辩(exam)\n");
        if (who->query("school/level")=="大学")
        say("请交100元考试费,到隔壁房间参加考试.\n");
        if (who->query("school/level")=="研究生")
        say("请交100元考试费,到隔壁房间参加答辩.\n");
        who->set("marks/exam", 1);
        return 1;
}

int accept_object(object me, object ob)
{
        object item;
        me = this_player();
        if ((!me->query("marks/exam")) && (!me->query("marks/e_exam")))
                return 0;
        if ( ob->value() != 10000) 
                return notify_fail("这里不能讨价还价,100元就是100元.\n");
        if (me->query("marks/exam")) {
                item = new(OBJ_DIR"toy/exam_t");
                item->set("nature", "毕业");
                item->set("giver", room_short);
                item->move(me);
                say(HIC"老师交给你一张准考证.\n"NOR);
//                command("give card to "+(string)me->query("id"));
                return 1;
        }
        if (me->query("marks/e_exam")) {
                item = new(OBJ_DIR"toy/exam_t");
                item->set("nature", "考大学");
                item->set("giver", room_short);
                item->move(me);
                say(HIC"老师交给你一张准考证.\n"NOR);
//                command("give card to "+(string)me->query("id"));
                return 1;
        }
}
