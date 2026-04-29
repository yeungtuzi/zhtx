// /obj/toy/rticket.c

inherit ITEM;

void create()
{
        set_name("火车票", ({ "railway ticket", "train ticket", "ticket" }));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张普通的火车票,可以乘开往各地的火车.\n"+
                "车票后印着:usage: wait train to <目的地车站名>\n" +
                "                       by mscat 19980702\n");
        set("value", 5000);
        }
}

void init()
{
        add_action("do_wait", "wait");
}

int do_wait(string arg)
{
        object room, item, who;
        string station_name, dest_name, start_name;
        if (!living(who=this_player()))
                return notify_fail("你现在无法等车.\n");
        if (!arg || (sscanf(arg, "train to %s", dest_name)!=1))
                return notify_fail("usage: wait train to <目的地车站名>\n");
        if (!objectp(room=environment(who)))
                return notify_fail("你现在无法等车.\n");
        if (!stringp(station_name = room->query("short")))
                return notify_fail("你现在无法等车.\n");
        if (sscanf(station_name, "%s火车站", start_name)!=1)
                return notify_fail("你得先到火车站去才能等到火车.\n");
        message_vision("$N在"+start_name+"火车站上耐心地等待开往"+ dest_name +
                "的火车.\n", who, room);
        if ((dest_name != "长安") && (dest_name != "边城")
                && (dest_name != "风暴角"))
                return notify_fail("你忽然想起,并没有开往"
                        +dest_name+"的列车.\n");
        if (!objectp(item=find_object(OBJ_DIR"toy/train")))
                return notify_fail("车站广播:开往"+
                        dest_name+"的列车暂时停班.\n");
        if ((item->query("in_use")) && (item->query("dest_name")!= dest_name))
                return notify_fail("车站广播:开往"+
                        dest_name+"晚点,请过几分钟再来候车.\n");
        message_vision("开往"+dest_name+"的火车开进"+start_name+
                "火车站停下了,$N匆匆忙忙登上车.\n", who, room);
        message_vision("$N刚刚上来,车就起动了.\n", who, item);
        item->set("in_use", 1);
        item->set("dest_name", dest_name);
        return 1;
}
