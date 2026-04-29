// room.c


#include <dbase.h>
#include <room.h>

inherit F_DBASE;
inherit F_CLEAN_UP;
inherit "/quest/killer/paths.c";

#include <ansi.h>
#define TOTAL_VALID_ROOM_N 86  //this have to be manually updated, flyaway
//read total valid room file to calculate this maybe too large to maintain memory
#define VALID_ROOM_FILE "/quest/roomlog"   //room log path, flyaway


nosave mapping doors;
nosave mapping guards;

int query_max_encumbrance() { return 100000000000; }

object make_inventory(string file)
{
        object ob;

        ob = new(file);

        // Support for uniqueness
        if( ob->violate_unique() ) ob = ob->create_replica();

        if( !ob ) return 0;

        ob->move(this_object());
        ob->set("startroom", base_name(this_object()));
        ob->return_home(this_object());
        return ob;
}

void reset()
{
        mapping ob_list, ob;
        string *list;
        int i,j;
        object *pig;

        //
        // Check loaded objects to match the objects specified in "objects"
        // while query("objects") is
        // ([ <object filename>: <amount>, ..... ])
        // and query_temp("objects") is
        // ([ <object filename>: ({ob1, ob2, ...}), .... ])
        //



        //clean_up的唯一好处就是当用户不多的时候能节省内存，
        //用户很多时，一个房间被清除出内存的时间不会很长，
        //频繁的换出和编译浪费了大量的CPU时间，而且有很多其他的问题。
        //不允许房间被清除，同时加上垃圾清除机制。
        // by YEUNG 2000-3-29

//      set("no_clean_up", 1);
        pig = all_inventory(this_object());
        i = sizeof(pig);
        while( i-- )
        {
                if( !pig[i]->is_character() ) destruct(pig[i]);
        }

        ob_list = query("objects");
        if( !mapp(ob_list) )
        {
                return;
        }

        if( !mapp(ob = query_temp("objects")) )
                ob = allocate_mapping(sizeof(ob_list));

        list = keys(ob_list);
        for(i=0; i<sizeof(list); i++) {
                // Allocate an array if we have multiple same object specified.
                if(     undefinedp(ob[list[i]])
                &&      intp(ob_list[list[i]])
                &&      ob_list[list[i]] > 1 )
                        ob[list[i]] = allocate(ob_list[list[i]]);

                switch(ob_list[list[i]]) {
                case 1:
//                      if( objectp(ob[list[i]]) ) destruct(ob[list[i]]);
                        if( !ob[list[i]] )
                                ob[list[i]] = make_inventory(list[i]);
                        if( environment(ob[list[i]]) != this_object()
                        &&      ob[list[i]]->is_character() ) {
                                if( !ob[list[i]]->return_home(this_object()) )
                                        add("no_clean_up", 1);
                        }

                        break;
                default:
                        for(j=0; j<ob_list[list[i]]; j++) {


                                // If the object is gone, make another one.
                                if( !objectp(ob[list[i]][j]) ) {
//added by yeung to force a room to recreate inventories.
//                              if( objectp(ob[list[i]][j]) ) destruct(ob[list[i]][j]);
                                        ob[list[i]][j] = make_inventory(list[i]);
                                        continue;
                                }


                                // Try to call the wandering npc come back here.
                                if( environment(ob[list[i]][j]) != this_object()
                                &&      ob[list[i]][j]->is_character() ) {
                                        if( !ob[list[i]][j]->return_home(this_object()) )
                                                add("no_clean_up", 1);
                                }
                        }
                }
        }
        set_temp("objects", ob);
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir)

{
        if( !mapp(doors) || undefinedp(doors[dir]) )
                return "你要看什麽？\n";
        if( doors[dir]["status"] & DOOR_CLOSED )
                return "这个" + doors[dir]["name"] + "是关著的。\n";
        else
                return 0;
//              return "这个" + doors[dir]["name"] + "是开著的。\n";
}

varargs int open_door(string dir, int from_other_side)
{
        mapping exits;
        object ob;

        if( !mapp(doors) || undefinedp(doors[dir]) )
                return notify_fail("这个方向没有门。\n");

        if( !from_other_side && !(doors[dir]["status"] & DOOR_CLOSED) )
                return notify_fail( doors[dir]["name"] + "已经是开著的了。\n");

        exits = query("exits");
        if( !mapp(exits) || undefinedp(exits[dir]) )

                error("Room: open_door: attempt to open a door with out an exit.\n");

        if( from_other_side ) {
                message("vision", "有人从另一边将" + doors[dir]["name"] + "打开了。\n", this_object());
        } else if( objectp(ob = find_object(exits[dir])) ) {
                if( !ob->open_door(doors[dir]["other_side_dir"], 1) )
                        return notify_fail("门的另一边好像卡住了。\n");
        }

        doors[dir]["status"] &= (!DOOR_CLOSED);
        return 1;
}

varargs int close_door(string dir, int from_other_side)
{
        mapping exits;
        object ob;

        if( !mapp(doors) || undefinedp(doors[dir]) )
                return notify_fail("这个方向没有门。\n");

        if( (doors[dir]["status"] & DOOR_CLOSED) )
                return notify_fail( doors[dir]["name"] + "已经是关著的了。\n");


        exits = query("exits");
        if( !mapp(exits) || undefinedp(exits[dir]) )
                error("Room: close_door: attempt to open a door with out an exit.\n");

        if( from_other_side )
                message("vision", "有人从另一边将" + doors[dir]["name"] + "关上了。\n", this_object());
        else if( objectp(ob = find_object(exits[dir])) ) {
                if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
        }

        doors[dir]["status"] |= DOOR_CLOSED;
        return 1;
}

int check_door(string dir, mapping door)
{
        // If we have no responding door, assume it is correct.
        if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;

        door["status"] = doors[dir]["status"];
        return 1;
}


varargs void create_door(string dir, mixed data, string other_side_dir, int status)
{
        mapping d, item_desc;
        object ob;
        string exit;

        if( !stringp(exit = query("exits/" + dir)) )
                error("Room: create_door: attempt to create a door without exit.\n");

        // String mode.
        if( stringp(data) ) {
                d = allocate_mapping(4);
                d["name"] = data;
                d["id"] = ({ dir, data, "door" });
                d["other_side_dir"] = other_side_dir;
                d["status"] = status;
        // Compelete specification mode.
        } else if( mapp(data) )
                d = data;
        else
                error("Create_door: Invalid door data, string or mapping expected.\n");


        set("item_desc/" + dir, (: look_door, dir :) );

        if( objectp(ob = find_object(exit)) ) {
                if( !ob->check_door(other_side_dir, d) )
                        return;
        }

        // Add the door.
        if( !mapp(doors) ) doors = ([ dir: d ]);
        else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
        if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
        else return doors[dir][prop];
}

int valid_leave(object me, string dir)
{
        int i, move_skill;

        string my_name;
        object guard, *ob;

        if( sizeof(ob = query("guarded/" + dir)) ) {
                move_skill = me->query_skill("move");
                my_name = me->name();
                for(i=0; i<sizeof(ob); i++) {
                        if( !ob[i]                                                      // If the guard still exists?
                        ||      ob[i]==me                                               // If the guard is ourself?
                        ||      !present(ob[i], this_object())  // If the guard is here?
                        ||      ob[i]->is_busy()                                // If the guard is busy?
                        ||      !living(ob[i])                                  // If the guard is concious?
                        ||      !ob[i]->visible(me)                             // Can the guard see us?
                        ||      ((string)ob[i]->query_temp("pending/guarding") != dir))
                                continue;
                        // Check move skill.
                        if( random(move_skill) < ob[i]->query_skill("move")/2 ) {
                                message_vision("$n想要从$N身边经过，但是被$N挡住了。\n", ob[i], me);
                                ob[i]->start_busy(1);
                                me->start_busy(1);
                                return notify_fail("你无法通过！\n");
                        }
                        tell_object(ob[i], my_name + "闪过你的阻挡！\n");

                        ob[i]->start_busy(1);
                }
        }

        if( mapp(doors) && !undefinedp(doors[dir]) ) {
                if( doors[dir]["status"] & DOOR_CLOSED )
                        return notify_fail("你必须先把" + doors[dir]["name"] + "打开！\n");
                // if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
        }
        return 1;
}

//Add by flyaway to make a list of rooms for quest -s
//May 4, 2003
void explorenear()
{
        mapping myexits;
        mixed* nearpaths;
        int i;
        myexits = query("exits");
        nearpaths=values(myexits);
        for(i=0;i<sizeof(nearpaths);i++)
             {
                         //call_other(find_object(nearpaths[i]),"explorerooms",
                          if (load_object(nearpaths[i])) load_object(nearpaths[i])->explorerooms();
             }
        write(base_name(this_object()) + "   -----    " + this_object()->query("short") + "\n");

}
void explorerooms()
{
        mapping npcs;
        mixed* npcpaths;
        string* abc;
        int i;
        object ob;
        if(query_temp("RMdata_OK")) return;    //room route already recorded
        log_file("roomlog",sprintf("/%O\n",this_object()),0);
        set_temp("RMdata_OK",1);
        call_out("explorenear",random(4));  //use call out to delay this recursive function.

        //log npc in this room to npclog file
        npcs = this_object()->query("objects");
        if (!npcs) return;
        npcpaths = keys(npcs);
        for(i=0;i<sizeof(npcpaths);i++)
        {
                ob=load_object(npcpaths[i]);
                //过滤动物
                if ( ob->query("race") && ob->query("race") == "野兽" )
                continue;
                //过滤随机名字NPC
                  if ( member_array("first_name", variables(ob)) != -1 ||
		     member_array("surname", variables(ob)) != -1 )
                {
                        log_file("rndnamelog",npcpaths[i] + "\n",0);
                        continue;
                }
                //过滤同一文件的clone在不同room中所产生的相同地址
                if (file_size("/log/npclog") > 0)
                {
                        abc = explode(read_file("/log/npclog"),"\n");
                        if (member_array(npcpaths[i],abc) != -1)
                        continue;
                }
                if (ob && ob->is_character()) log_file("npclog",npcpaths[i] + "\n",0);
        }   //end of for

}



//End of flyaway
//May 4 2003



void setup()
{
        seteuid(getuid());
        this_object()->reset();
}

