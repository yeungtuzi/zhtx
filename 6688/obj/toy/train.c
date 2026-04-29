// /obj/toy/train.c

inherit ROOM;
void do_arrive(object who);

void create()
{
        set("short", "火车");
        set("long", @LONG
这是一节普通的火车车厢,里面坐满了来自四方的旅客,有些来得稍晚的人只有
站着了.
LONG
        );
        set("in_use", 0);
        set("dest_name", "长安");
        setup();
}

void init()
{
        object who;
        int resttime;
        if (interactive(who=this_player())) {
                resttime = random(33);
                who->start_busy(resttime);
                remove_call_out("do_arrive");
                call_out("do_arrive", resttime, who);
        }
}

void do_arrive(object who)
{
        object room, item;
        string dest_name;
        if (!objectp(item = environment(who)) 
                || (item->query("name") != "火车")) {
                message_vision("$N正在虚空中飞行.\n", who);
                return;
        }
        item->set("in_use", 0);
        if (!living(who)) {
                who->move(VOID_OB);
                return;
        }
        if (!stringp(dest_name=item->query("dest_name"))) {
                message_vision("列车广播:紧急故障停车!\n", who);
                who->move(VOID_OB);
                return;
        }
        if ((dest_name!= "长安") && (dest_name != "边城")
                && (dest_name != "风暴角")) dest_name="长安";
        if (dest_name=="长安") {
        message_vision("列车在长安火车站停了下来,$N和许多旅客一起下车.\n",
                who);
                room=find_object("/d/border_c/cstation");
                who->move(room);
                return;
        }
        if (dest_name=="边城") {
        message_vision("列车在边城火车站停了下来,$N和几个旅客一起下车.\n",
                who);
                room=find_object("/d/border_c/station");
                who->move(room);
                return;
        }
        if (dest_name=="风暴角") {
        message_vision("列车在风暴角火车站停了下来,好象只有$N一个人下车.\n",
                who);
                room=find_object("/d/siberia/station");
                who->move(room);
                return;
        }
}
