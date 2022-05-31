# RFC : Client Documentation

## Synopsis
The point of this documentation is to provide the Client protocol. Created by louison.kalifa@epitech.eu, maxime.lecomte@epitech.eu and leny.wilhelm@epitech.eu.
It provide all the commands from out protocol. These commands will be send to the server where they must be handle.

## Background
This documentation is a part of the project My_teams.
The goal of the project is to create a server that communicates with clients and handle commands from the clients.
The client and the server have a protocol with every single commands describe.
You can find the Client_doc and the Server_doc for each protocol.
[My_teams](https://intra.epitech.eu/module/2021/B-NWP-400/BDX-4-1/acti-501643/project/file/B-NWP-400_myTeams.pdf)
## Protocol
C:Help : Print out the usage to help the client
C:Login:user_name : Create a new client with the user_name or connect the client to the on who already have user_name
C:Logout : Disconnect the client from the server
C:Users : Get the list of all users that exist in the domain
C:User:user_uuid : Get informations about an unique user
C:Send:user_uuid:message_body : Send a message to an user
C:Messages:user_uuid : List all messages exchange with an user
C:Subscribe:team_uuid : Subscribe to the event of a team and its sub directories (enable reception of all events from a team)
C:Subscribed : List all subscribed teams
C:SubscribedTeam:team_uuid : List all users subscribed to a team
C:Unsubscribe:team_uuid : Unsubscribe from a team
C:Use : You go at the root
C:UseTeam:team_uuid : Use the specified team
C:UseChannel:team_uuid:channel_uuid : Use the specified channel
C:UseThread:team_uuid:channel_uuid:thread_uuid : Use the specified thread
C:CreateTeam:team_name:team_description : Create a new team
C:CreateChannel:team_uuid:channel_name:channel_description : Create a new channel
C:CreateThread:team_uuid:channel_uuid:thread_title:thread_message : Create a new thread
C:CreateComment:team_uuid:channel_uuid:thread_uuid:comment_body : Create a new reply
C:ListTeams : List all existing teams
C:ListChannels:team_uuid : List all existing channels
C:ListThreads:team_uuid:channel_uuid : List all existing threads
C:ListComments:team_uuid:channel_uuid:thread_uuid : List all existing comments
C:InfoUser : Display currently logged users info
C:InfoTeam:team_uuid : Display all informations of the specified team
C:InfoChannel:team_uuid:channel_uuid : Display all informations of the specified channel
C:InfoThread:team_uuid:channel_uuid:thread_uuid : Display all informations of the specified thread