// channeld.c
 
#include <ansi.h>
#include <net/dns.h>
 
mapping channels = ([
        "sys":  ([      "msg_speak": HIB "【系统】%s：%s\n" NOR, "wiz_only": 1 ]),
        "wiz":  ([      "msg_speak": HIY "【巫师】%s：%s\n" NOR,
                                "msg_emote": HIY "【巫师】%s" NOR,
                                "wiz_only": 1
                        ]),
        "gwiz": ([      "msg_speak": HIG "【网际巫师】%s：%s\n" NOR,
                                "msg_emote": HIG "【网际巫师】%s\n" NOR,
                                "wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
                                "filter": (: $1["MUDLIB"]=="Venturing in a New World" :),
                                "intermud_emote": 1 ]),
        "zh":   ([      "msg_speak": HIG "【纵横天下】%s：%s\n" NOR,
                                "msg_emote": HIG "【纵横天下】%s" NOR,
                                "intermud": GCHANNEL, "channel": "zh",
                                "filter": (: $1["MUDLIB"]=="Venturing in a New World" :) ,
                                "intermud_emote": 1
                ]),
        "cwiz": ([      "msg_speak": HIW "【全球巫师】%s：%s\n" NOR,
                                "msg_emote": HIW "【全球巫师】%s" NOR,
                                "wiz_only":1, "intermud": GCHANNEL, "channel": "cwiz",
                                "filter": (: $1["HOSTADDRESS"][0..2]=="159" :) 
                        ]),
        "chat": ([      "msg_speak": HIC "【闲聊】%s：%s\n" NOR,
                                "msg_emote": HIC "【闲聊】%s" NOR,
                                "filter": (: $1["MUDLIB"]=="Venturing in a New World" :) ,
                         ]),
        "bid":  ([      "msg_speak": HIW "【拍卖】%s：%s\n" NOR,
                                "msg_emote": HIW "【拍卖】%s" NOR,
                                "new_use":1
                         ]),
        "rumor":([      "msg_speak": HIM "【谣言】%s：%s\n" NOR,
                                "msg_emote": HIM "【谣言】%s" NOR,
                                "filter": (: $1["MUDLIB"]=="Venturing in a New World" :) ,
                                "anonymous": "某人"
                        ]),
        "music":([      "msg_speak": WHT "【心笙乐府】%s唱著：%s\n" NOR,
                                "msg_emote": WHT "【心笙乐府】%s" NOR
                         ]),
        "new":  ([      "msg_speak": HIG "【新手】%s：%s\n" NOR,
                                "msg_emote": HIC "【新手】%s" NOR,
                                "new_use":1
                        ]),
        "ann":  ([      "msg_speak": HIY "【本站通知】%s：%s\n" NOR,
                                "msg_emote": HIY "【本站通知】%s" NOR,
                                "announce" : 1,                        
                                "wiz_only": 1,
                        ]),
        "gann":  ([      "msg_speak": HIY "【纵横天下通知】%s：%s\n" NOR,
                                "msg_emote": HIY "【纵横天下通知】%s" NOR,
                                "announce" : 1,                        
                                "wiz_only": 1,
                                "intermud": GWIZ, "channel": "gann",
                                "filter": (: $1["MUDLIB"]=="Venturing in a New World" :),       
                                "intermud_emote": 1                     
                        ]),
                        
]);
 
void create()
{
        seteuid(getuid());      // This is required to pass intermud access check.
}
 
varargs int do_channel(mixed me, string verb, string arg, int emote)
{
        object *ob,*wizs;
        string *tuned_ch, who;

        if( verb== "" ) return 0;
        
        if( me->query("chblk_on")||me->query("chblk_chat") ){
           return notify_fail("你的聊天频道已被关闭\n");
        }
        if( me->query("chblk_rumor") ){
           return notify_fail("你的谣言频道已被关闭\n");
        }
 
        // Check if this is a channel emote.
        if( verb[<1] == '*' ) {
                emote = 1;
                verb = verb[0..<2];
        }
 
        if( !mapp(channels) || undefinedp(channels[verb]) )
                return 0;

        ob = filter_array( users(), "filter_listener", this_object(), channels[verb]);  
        if( channels[verb]["anonymous"] )
                wizs = filter_array( users(), "is_wiz", this_object() );

        // 支持intermud频道的emote,但是要有区分
        if( channels[verb]["intermud_emote"] && me->query("channel_id") )
        {
                message( "channel:" + verb,
                        sprintf( channels[verb]["msg_speak"], me->query("channel_id"), arg ), ob );                   
                return 1;
        }

        if( !objectp(me) )
        {
                if( stringp(me) )
                {
                        if( channels[verb]["anonymous"] && ( random(10)>1) ) 
                        {
                                who = channels[verb]["anonymous"];
                        }
                        else
                                who = me;

                        message( "channel:" + verb,
                        sprintf( channels[verb]["msg_speak"], who, arg ), ob );
                        //巫师总是可以看到造谣者
                        if(channels[verb]["anonymous"])
                        {
                        
                                message( "channel:" + verb,
                                        sprintf( channels[verb]["msg_speak"], me, arg ), wizs );                      
                        }                                                       
                        return 1;
                }
                return 0;
        }

        if( 1 ) {
                if(channels[verb]["wiz_only"] && !wizardp(me) && !raw_wiz_level(me) && (userp(me) || channels[verb]["announce"]) )
                        return 0;

                // If we speaks something in this channel, then must tune it in.
                tuned_ch = me->query("channels");
                if( !pointerp(tuned_ch) )
                        me->set("channels", ({ verb }) );
                else if( member_array(verb, tuned_ch)==-1 )
                        me->set("channels", tuned_ch + ({ verb }) );

                if(!channels[verb]["new_use"] && (int)me->query("mud_age") < 172800 && !wizardp(me) && userp(me) && !raw_wiz_level(me))
                        return notify_fail("你现在还没有权力使用这个频道。\n");
 
                if( verb == "bid" && userp(me) )        return 0;

                // Support of channel emote
                if( emote ) {
                        string vb, emote_arg;
 
                        if (!arg) {
                                arg = (string)me->name()+"看起来表情丰富。\n";
                        } else {
                        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
                                vb = arg;
                                emote_arg = "";
                        }
                        arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);
                        if ( (!arg) && (!is_chinese(vb))) return 0;
                        if( (!arg) && (is_chinese(vb)) ) 
                        arg=(string)me->name()+vb+" "+emote_arg+"\n";
                        }
                }         
        if( arg==(string)me->query_temp("last_channel_msg") && userp(me) )
            return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");
 
        }
 
        // Make the identity of speaker.
 
        
        if( channels[verb]["anonymous"] && (( random(10)>1) || wizardp(me)) ) 
        {
                who = channels[verb]["anonymous"];
        }
        else if( userp(me) || !stringp(who = me->query("channel_id")) )
                who = me->query("name") + "(" + capitalize(me->query("id")) + ")";
 
        // Ok, now send the message to those people listening us.
 
                
        if( !arg ) arg = "...";
                
        arg = REPLACE_D->ansi_remove(arg);
        
        if( emote ) {

                message( "channel:" + verb,
                        sprintf( channels[verb]["msg_emote"], arg ), ob );

                //巫师总是可以看到造谣者
                if(channels[verb]["anonymous"])
                {
                        message( "channel:" + verb,
                                MAG+me->query("name") + "(" + capitalize(me->query("id")) + ")："+
                                sprintf( channels[verb]["msg_emote"], arg ), wizs );                    
                }            

        } else
        {
                who = REPLACE_D->ansi_remove(who);
                message( "channel:" + verb,
                        sprintf( channels[verb]["msg_speak"], who, arg ), ob );
                //巫师总是可以看到造谣者
                if(channels[verb]["anonymous"])
                {
                        
                        message( "channel:" + verb,
                                sprintf( channels[verb]["msg_speak"], REPLACE_D->ansi_remove(me->query("name"))
                                + "(" + capitalize(me->query("id")) + ")", arg ), wizs );                      
                }
        }
        
        if( arrayp(channels[verb]["extra_listener"]) ) {
                channels[verb]["extra_listener"] -= ({ 0 });
                if( sizeof(channels[verb]["extra_listener"]) )
                        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
        }

        
        if( !undefinedp(channels[verb]["intermud"])
        &&      base_name(me) != channels[verb]["intermud"] )
                channels[verb]["intermud"]->send_msg(
                        channels[verb]["channel"], me->query("id"), me->name(1), arg, emote,
                        channels[verb]["filter"] );
 
        if( userp(me) ) 
                me->set_temp("last_channel_msg", arg);
 
        return 1;
}
 
int is_wiz(object ppl)
{
        if( !environment(ppl) ) return 0;
        return wiz_level(ppl)||raw_wiz_level(ppl);
}

int filter_listener(object ppl, mapping ch)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl) ) return 0;

        if( ch["announce"] ) return 1;
        if( ch["wiz_only"] ) return (wizardp(ppl)||raw_wiz_level(ppl));
        if( ch["anonymous"] ) return (!wizardp(ppl) && !raw_wiz_level(ppl));
        return 1;
}
 
void register_relay_channel(string channel)
{
        object ob;
 
        ob = previous_object();
        if( undefinedp(channels[channel]) || !ob) return;
        if( arrayp(channels[channel]["extra_listener"]) ) {
                if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
                channels[channel]["extra_listener"] += ({ ob });
        } else
                channels[channel]["extra_listener"] = ({ ob });
}

string valid_intermud(string channel) {

        return(channels[channel]["intermud"]);
}

string valid_announce(string channel) {

        return(channels[channel]["announce"]);
}


