import os
import random
from discord.ext import commands

import discord
from dotenv import load_dotenv

load_dotenv()
TOKEN = os.getenv("TOKEN")
GUILD = os.getenv("GUILD")
client = discord.Client()

bot = commands.Bot(command_prefix="!")

@bot.event
async def on_ready():
    print(f'{bot.user.name} has connected to Discord!')
    
@client.event
async def on_ready_s():
    for guild in client.guilds:
        if guild.name == GUILD:
            break
        
    print(f'{client.user} has connected to the following guild: {guild.name} and its ID: {guild.id}')
    

@bot.command(name='create-channel')
@commands.has_role('admin')
async def create_channel(ctx, channel_name='new_channel'):
    guild = ctx.guild
    existing_channel = discord.utils.get(guild.channels, name=channel_name)
    if not existing_channel:
        print(f'Creating a new channel: {channel_name}')
        await guild.create_text_channel(channel_name)

@client.event
async def on_member_join(member):
    
    await member.create_dm()
    await member.dm_channel.send("Welcome to my guild!")

@bot.command(name="office", help='says random The Office quote')
async def office(ctx):

    
    office = ["Stupid corporate... wet blankets. Like booze ever killed anybody.", "Close your mouth sweetie you look like a trout.", "Don't sell your implants please."]
    response = random.choice(office)
    await ctx.send(response)


bot.run(TOKEN)